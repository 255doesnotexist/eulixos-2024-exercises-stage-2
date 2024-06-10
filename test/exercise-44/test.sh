#!/usr/bin/env bash

EXECUTABLE=$1

EXPECTED_STDOUT=$(printf "Sum of array elements is 15")

STDOUT=$(timeout 10s $EXECUTABLE 5 1,2,3,4,5 || true)

if [ "$STDOUT" == "$EXPECTED_STDOUT" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$EXPECTED_OUTPUT' but got '$STDOUT'"
  exit 1
fi
