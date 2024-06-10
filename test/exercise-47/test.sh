#!/usr/bin/env bash

EXECUTABLE=$1

EXPECTED_STDOUT=$(printf "Occurrences of target:3")

STDOUT=$(timeout 10s $EXECUTABLE 7 2,3,4,5,2,2,6 2 || true)

if [ "$STDOUT" == "$EXPECTED_STDOUT" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$EXPECTED_OUTPUT' but got '$STDOUT'"
  exit 1
fi
