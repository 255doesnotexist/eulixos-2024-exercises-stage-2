#!/usr/bin/env bash

EXECUTABLE=$1

EXPECTED_STDOUT=$(printf "Transposed Matrix:\n1 4 7 \n2 5 8 \n3 6 9 \n")

STDOUT=$($EXECUTABLE "1,2,3,4,5,6,7,8,9")

if [ "$STDOUT" == "$EXPECTED_STDOUT" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$EXPECTED_STDOUT' but got '$STDOUT'"
  exit 1
fi
