# Nitro C++ Proficiency Test
Nitro C++ Proficiency Test.<br/><br/>

## Author note
```
/src : source code
/tests : unit tests
/tools : cmake utilities
/.vscode : IDE setup
/external : Unit tests single include library Catch2
```
Algorithm insights:<br/>
Brute forcing the problem means checking n! (factorial) combinations for n input rectangles, this is not ideal. Instead we know 2 things:
- A&B is the same as B&A which means we can skip combinations where the index of the second element is smaller than the first.
- An intersection of 3 rectangles only exists if the simpler intersection of 2 rectangles exists

## Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.<br/><br/>

## Build dependencies
These are the dependencies for the compilation of all the targets
```
cmake
cmake-format
clang-format
```
<br/>

# Build instructions for development
## Setup run/dev environment
```
# Catch2 lib for unit tests
git submodule update --init --recursive
apt install cmake cmake-format clang-format build-essential
```

## Run the console application
```
mkdir build
cd build || exit

#Build binary
cmake -DCMAKE_BUILD_TYPE=Debug ..
make all -j"$(nproc)"

#Run project executable
#Change ../example.json to the json filepath
./Nitro ../example.json
```

## Run unit tests
```
cd build || exit
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_TESTS=ON ..
make all
make test
```

## Future work
- Documentation doxygen
- Dynamic analysis
- Static analysis hook
- Coverage
<br/><br/>

## Authors
* **Nolasco Napoleao** - [nolasconapoleao](https://github.com/nolasconapoleao)
