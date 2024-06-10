#!/usr/bin/env bash

EXECUTABLE=$1

EXPECTED_STDOUT=$(printf "Original matrix:\n1 5 9 \n10 11 13 \n12 13 15 \nThe 6th smallest element in the matrix is: 12\n")

STDOUT=$($EXECUTABLE 3 6 3 3 3 1 5 9 10 11 13 12 13 15)

if [ "$STDOUT" == "$EXPECTED_STDOUT" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$EXPECTED_STDOUT' but got '$STDOUT'"
  exit 1
fi
