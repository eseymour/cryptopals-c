#! /usr/bin/env bash

input=1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736
expected="Cooking MC's like a pound of bacon"

if [[ $(diff <(./decodexor $input | cut -d \" -f2) <(echo $expected)) ]]; then
  echo "ERROR: Program output different encrypted string than expected"
  exit 1
fi
