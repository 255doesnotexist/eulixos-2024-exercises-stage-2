#!/usr/bin/env bash

EXECUTABLE=$1

EXPECTED_STDOUT=$(printf "P1:28,28,18\nP2:22,21,15\nP3:26,24,16\nP4:16,13,9")

STDOUT=$($EXECUTABLE)

if [ "$STDOUT" == "$EXPECTED_STDOUT" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$EXPECTED_STDOUT' but got '$STDOUT'"
  exit 1
fi
