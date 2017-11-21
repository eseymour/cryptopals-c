#! /usr/bin/env bash

input=49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d
expected=SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t

if [[ $(diff <(./hex2base64 $input) <(echo $expected)) ]]; then
  echo "ERROR: Program output different base64 string than expected"
  exit 1
fi
