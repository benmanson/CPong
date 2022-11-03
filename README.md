# CPong

Clone the repository with the ```--recurse-submodules``` flag set:

```bash
git clone --recurse-submodules git@github.com:benmanson/CPong.git
```

In the root directory, run the command:

```bash
cmake -S . -B build && cmake --build build
```

Then you can run the program from the root directory using:

```bash
./build/pong
```

You can run the tests using:

```bash
./build/test/pong_tests
```

TODO:
  - Add scoreboard
  - Add sound
