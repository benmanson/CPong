# CPong

Clone the repository with the ```--recursively``` flag set, and install the dependencies: SDL2, SDL2_ttf, and SDL2_mixer. For example, on MacOS with Homebrew:

```bash
brew install sdl2 sdl2_ttf sdl2_mixer
```

In the root directory, run the commands:

```bash
cmake -S . -B build

cmake --build build
```

Then you can run the program using:

```bash
./build/pong
```

Or run the tests using:

```bash
./build/test/pong_tests
```
