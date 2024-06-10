#!/usr/bin/env bash

EXECUTABLE=$1

EXPECTED_STDOUT=$(printf "Access:1,Frames: [1,-1,-1]\nAccess:2,Frames: [1,2,-1]\nAccess:3,Frames: [1,2,3]\nAccess:4,Frames: [4,2,3]\nAccess:1,Frames: [4,1,3]\nAccess:2,Frames: [4,1,2]\nAccess:5,Frames: [5,1,2]\nAccess:1,Frames: [5,1,2]\nAccess:2,Frames: [5,1,2]\nAccess:3,Frames: [3,1,2]\nAccess:4,Frames: [3,4,2]\nAccess:5,Frames: [3,4,5]\n
")

STDOUT=$($EXECUTABLE 1,2,3,4,1,2,5,1,2,3,4,5 3)

if [ "$STDOUT" == "$EXPECTED_STDOUT" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$EXPECTED_STDOUT' but got '$STDOUT'"
  exit 1
fi
