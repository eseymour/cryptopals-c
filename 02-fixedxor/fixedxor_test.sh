#! /usr/bin/env bash

message=1c0111001f010100061a024b53535009181c
key=686974207468652062756c6c277320657965
expected=746865206b696420646f6e277420706c6179

if [[ $(diff <(./fixedxor $message $key) <(echo $expected)) ]]; then
  echo "ERROR: Program output different encrypted string than expected"
  exit 1
fi
