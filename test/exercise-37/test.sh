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

echo "Waiting for timer callback..."
sleep 6

echo "Unloading module $KO..."
rmmod "$KO"
if [ $? -ne 0 ]; then
  echo "Failed to unload module $KO."
  exit 1
fi

MODULE_MESSAGE=$(dmesg | grep "Timer callback function called")

if [ -n "$MODULE_MESSAGE" ]; then
  echo "Test passed."
  echo "$MODULE_MESSAGE"
  exit 0
else
  echo "Test failed. Expected timer callback message but got none."
  exit 1
fi
