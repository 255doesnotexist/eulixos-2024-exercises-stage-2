#!/usr/bin/env bash

EXECUTABLE=$1

if [ -z "$EXECUTABLE" ]; then
  echo "Usage: $0 <path_to_module.ko>"
  exit 1
fi

KO=$(readelf -s ${EXECUTABLE} | grep FILE | sed '1d' | awk '{print $8}')

if [ ! -f "$EXECUTABLE" ]; then
  echo "Module file $EXECUTABLE not found."
  exit 1
fi

dmesg -c >/dev/null

echo "Loading module $KO..."
insmod "$EXECUTABLE" message="hello"
if [ $? -ne 0 ]; then
  echo "Failed to load module $KO."
  exit 1
fi

sleep 1

MAJOR=$(dmesg | grep "Registered a major number" | awk '{print $NF}')
if [ -z "$MAJOR" ]; then
  echo "Failed to retrieve major number from dmesg."
  rmmod "${KO%.c}"
  exit 1
fi

DEVICE="/dev/mychardev"
mknod $DEVICE c $MAJOR 0
chmod 666 $DEVICE

echo "Reading from device..."
DEVICE_OUTPUT=$(cat $DEVICE)

echo "Unloading module $KO..."
rmmod "${KO%.c}"
if [ $? -ne 0 ]; then
  echo "Failed to unload module $KO."
  exit 1
fi

rm -f $DEVICE

EXPECTED_OUTPUT="hello"
if [ "$DEVICE_OUTPUT" == "$EXPECTED_OUTPUT" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$EXPECTED_OUTPUT' but got '$DEVICE_OUTPUT'"
  exit 1
fi
