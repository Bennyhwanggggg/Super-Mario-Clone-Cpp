# Super Mario Clone
Super Mario Clone made using C++ and SDL2.  

## Build Pre-requisites
Windows:
Install the `Runtime Binary` [here](https://www.libsdl.org/download-2.0.php)

FreeBSD:
```
pkg install cmake sdl2 sdl2_image sdl2_mixer
```

Mac OS X:
Install the `Runtime Binary` [here](https://www.libsdl.org/download-2.0.php)  
Alternatively using brew:
```
brew install cmake sdl2 sdl2_image sdl2_mixer
```

## Building and running

```
make build run
```
or 
```
mkdir build
cd build
cmake ..
make
./uMario
```