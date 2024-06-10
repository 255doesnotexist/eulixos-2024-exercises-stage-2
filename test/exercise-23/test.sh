#!/usr/bin/env bash

EXECUTABLE=$1

EXPECTED_STDOUT=$(printf "Result:\n-6 -6 -6 \n-6 -6 -6 \n-6 -6 -6 \n")

STDOUT=$($EXECUTABLE "1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25" "1,0,-1,1,0,-1,1,0,-1")

if [ "$STDOUT" == "$EXPECTED_STDOUT" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$EXPECTED_STDOUT' but got '$STDOUT'"
  exit 1
fi
