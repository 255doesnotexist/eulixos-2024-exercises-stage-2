#!/usr/bin/env bash

EXECUTABLE=$1

EXPECTED_STDOUT=$(printf "Physical_Address：0x20002234")

STDOUT=$($EXECUTABLE 0x00002234)

if [ "$STDOUT" == "$EXPECTED_STDOUT" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$EXPECTED_STDOUT' but got '$STDOUT'"
  exit 1
fi
