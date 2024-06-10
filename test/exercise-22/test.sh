#!/usr/bin/env bash

EXECUTABLE=$1

EXPECTED_STDOUT=$(printf "Result:\n30 24 18 \n84 69 54 \n138 114 90 \n")

STDOUT=$($EXECUTABLE "1,2,3,4,5,6,7,8,9" "9,8,7,6,5,4,3,2,1")

if [ "$STDOUT" == "$EXPECTED_STDOUT" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$EXPECTED_STDOUT' but got '$STDOUT'"
  exit 1
fi
