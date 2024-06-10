#!/usr/bin/env bash

EXECUTABLE=$1

EXPECTED_STDOUT=$(printf "Fibonacci number at position 10 is 55")

STDOUT=$(timeout 10s $EXECUTABLE 10 || true)

if [ "$STDOUT" == "$EXPECTED_STDOUT" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$EXPECTED_OUTPUT' but got '$STDOUT'"
  exit 1
fi
