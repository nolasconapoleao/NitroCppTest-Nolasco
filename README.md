# Nitro C++ Proficiency Test
Nitro C++ Proficiency Test.<br/><br/>

## Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.<br/><br/>

## Build dependencies
These are the dependencies for the compilation of all the targets
```
cmake
```
<br/>

# Build instructions for development
## Create make files for each target (via cmake)
Run the cmake command and output the make recipe in the build folder
```
mkdir build
cd build || exit
#Build binary
cmake -DCMAKE_BUILD_TYPE=Debug  ..
make all -j"$(nproc)"
#Run binary
./Nitro
```

Run unit tests by running
```
make all && make test
```

## Future work
- TODO
<br/><br/>

## Authors
* **Nolasco Napoleao** - [nolasconapoleao](https://github.com/nolasconapoleao)
