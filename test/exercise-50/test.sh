#!/usr/bin/env bash

EXECUTABLE=$1

EXPECTED_STDOUT=$(printf "Access:0,Frames: [0,-1,-1,-1]\nAccess:1,Frames: [0,1,-1,-1]\nAccess:2,Frames: [0,1,2,-1]\nAccess:3,Frames: [0,1,2,3]\nAccess:4,Frames: [4,1,2,3]\nAccess:5,Frames: [4,5,2,3]\nAccess:0,Frames: [4,5,0,3]\nAccess:1,Frames: [4,5,0,1]\nAccess:2,Frames: [2,5,0,1]\nAccess:3,Frames: [2,3,0,1]\nAccess:4,Frames: [2,3,4,1]\nAccess:5,Frames: [2,3,4,5]\n
")

STDOUT=$($EXECUTABLE 0,1,2,3,4,5,0,1,2,3,4,5 4)

if [ "$STDOUT" == "$EXPECTED_STDOUT" ]; then
  echo "Test passed."
  exit 0
else
  echo "Test failed. Expected '$EXPECTED_STDOUT' but got '$STDOUT'"
  exit 1
fi
