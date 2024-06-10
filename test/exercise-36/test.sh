#!/usr/bin/env bash

EXECUTABLE=$1

KO=$(readelf -s ${EXECUTABLE} | grep FILE | sed '1d' | awk '{print $8}')

insmod $EXECUTABLE input_str="8,3,12,6,20"

MODULE_MESSAGE=$(dmesg | grep "Maximum value in the array: 20")

rmmod ${KO%.c}

if [ ! -z "$MODULE_MESSAGE" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected have '$MODULE_MESSAGE' but got empty"
  exit 1
fi
