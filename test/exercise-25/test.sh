#!/usr/bin/env bash

EXECUTABLE=$1

EXPECTED_STDOUT=$(printf "Original matrix:\n1 0 3 4 \n5 6 7 8 \n9 10 11 0 \n\nModified matrix:\n0 0 0 0 \n5 0 7 0 \n0 0 0 0 \n")

STDOUT=$($EXECUTABLE 3 4 4 4 1 0 3 4 5 6 7 8 9 10 11 0)

if [ "$STDOUT" == "$EXPECTED_STDOUT" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$EXPECTED_STDOUT' but got '$STDOUT'"
  exit 1
fi
