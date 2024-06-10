#!/usr/bin/env bash

EXECUTABLE=$1

EXPECTED_STDOUT=$(printf "Array is not sorted.")

STDOUT=$(timeout 10s $EXECUTABLE 5 2,5,1,8,4 || true)

if [ "$STDOUT" == "$EXPECTED_STDOUT" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$EXPECTED_OUTPUT' but got '$STDOUT'"
  exit 1
fi
