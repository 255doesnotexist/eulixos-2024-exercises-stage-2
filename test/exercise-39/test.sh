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
insmod "$EXECUTABLE"
if [ $? -ne 0 ]; then
  echo "Failed to load module $KO."
  exit 1
fi

sleep 1

dmesg_output=$(dmesg | grep "File operation successful")

rmmod "${KO%.c}"
if [ $? -ne 0 ]; then
  echo "Failed to unload module $KO."
  exit 1
fi

expected_output="File operation successful"
if [[ $dmesg_output == *"$expected_output"* ]]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$expected_output' but got '$dmesg_output'"
  exit 1
fi
