#!/usr/bin/env bash

EXECUTABLE=$1

EXPECTED_STDOUT=$(hostname)

STDOUT=$($EXECUTABLE)

if [ "$STDOUT" == "$EXPECTED_STDOUT" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$EXPECTED_STDOUT' but got '$STDOUT'"
  exit 1
fi
