# cryptopals-c

This repository is archived for reference. I have decided to solve the
challenges in Go at the [eseymour/cryptopals](https://github.com/eseymour/cryptopals)
GitHub repository. The original readme follows.

## Cryptopals Crypto Challenges
This repository contains programs written in C to solve the [Crytopals Crypto
Challenges](https://cryptopals.com).

### Building

This project uses the [tup](http://gittup.org/tup) build system. Once installed,
building the project is as simple as running the following command in your
shell:

```shell
tup
```

A makefile is also provided for tasks that tup cannot accomplish. The project
can also be built through make which just wraps tup:

```shell
make
```

### Progress

#### Set 1

| #   | Challenge                        | Completed         |
| --- | -------------------------------- | ----------------- |
| 1   | [Convert hex to base64][1]       | October 9, 2017   |
| 2   | [Fixed XOR][2]                   | December 19, 2017 |
| 3   | [Single-byte XOR cipher][3]      | December 20, 2017 |
| 4   | [Detect single-character XOR][4] | Work in Progress  |
| 5   | [Implement repeating-key XOR][5] | December 23, 2017 |
| 6   | [Break repeating-key XOR][6]     |                   |
| 7   | [AES in ECB mode][7]             |                   |
| 8   | [Detect AES in ECB mode][8]      |                   |

[1]: https://cryptopals.com/sets/1/challenges/1
[2]: https://cryptopals.com/sets/1/challenges/2
[3]: https://cryptopals.com/sets/1/challenges/3
[4]: https://cryptopals.com/sets/1/challenges/4
[5]: https://cryptopals.com/sets/1/challenges/5
[6]: https://cryptopals.com/sets/1/challenges/6
[7]: https://cryptopals.com/sets/1/challenges/7
[8]: https://cryptopals.com/sets/1/challenges/8
