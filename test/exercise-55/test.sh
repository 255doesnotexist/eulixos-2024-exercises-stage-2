#!/usr/bin/env bash

EXECUTABLE=$1

EXPECTED_STDOUT=$(printf "malloc failed: Cannot allocate memory" )

STDOUT=$($EXECUTABLE 2>&1 | grep "malloc failed: Cannot allocate memory")

if [ "$STDOUT" == "$EXPECTED_STDOUT" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$EXPECTED_STDOUT' but got '$STDOUT'"
  exit 1
fi
