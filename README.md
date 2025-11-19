# 📖 INI parser

This library is a C++ parser for `.INI` files.

## Getting started

### 1. Build

1. Clone the repository
```shell
git clone git@github.com:lypitech/ini-parser.git
cd ini-parser/
```

2. Build the project
```shell
# Configure and generate build files
cmake -B build/

# Compile the project
cmake --build build/
```

If you want the build to be faster (to use all of your CPU cores), simply add `--parallel` to the options!

Library file will be located in the `build/` folder.  
If you want to build the project in another folder, simply replace `build/` with the folder you want the library to be
built in.
Make sure the folder you specify is empty!

### 2. Link

#### 2.1 CMake

If you use CMake, using this library in your project is really simple.

Simply include the following lines to your `CMakeLists.txt`:
```cmake
add_subdirectory(<library file path>)

target_include_directories(${PROJECT_NAME} PRIVATE
    <library file path>/include
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    iniparser
)
```

#### 2.2 Manual linking

If you don't use a proper build system, you can still manually link the library to your project when compiling it.

Simply include the following to your compilation flags:
```
-L <library file path> -l iniparser
```

## How it works

TODO

## How to use

### 1. Initialize the Parser

TODO

### 2. Usage

TODO

## Contributing

TODO

---

###### You can reach me here: [esteban.bouyault-yvanez@epitech.eu](mailto:esteban.bouyault-yvanez@epitech.eu)
