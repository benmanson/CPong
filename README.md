# CPong

## Requirements

- CMake >= 3.10
- C compiler i.e. clang, gcc
- C++ compiler (for tests) i.e. clang, g++

## Usage

### Build

Clone the repository with the ```--recurse-submodules --shallow-submodules``` flags set:

```bash
git clone --recurse-submodules --shallow-submodules git@github.com:benmanson/CPong.git
```

In the root directory, run the command:

```bash
cmake -S . -B build && cmake --build build
```

### Running

After building, you can run the program from the root directory using:

```bash
./build/pong
```

You can run the tests using:

```bash
./build/test/pong_tests
```

**TODO:**
  - Add scoreboard
  - Add sound
