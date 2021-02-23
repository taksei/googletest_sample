# Sample project for googletest

This project is a sample project using googletest.

## Install googletest

Install googletest into ~/local/gtest-1.10.0

```linux
git clone https://github.com/google/googletest.git -b release-1.10.0 --depth=1
cd googletest
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=~/local/gtest-1.10.0 ..
make -j 8 install
```

## Directory

Directory structure for this project is bellow.

~~~linux
.
├── CMakeLists.txt       : cmake setting to build this project
├── README.md            : this file
├── include
│   └── gtestsample      : project public headers
├── src
│   └── CMakeLists.txt   : cmake setting to build source files
└── test
    └── CMakeLists.txt   : cmake setting to build test files
~~~


## Build and Run test

Build this project in the build directory.

Add -DENABLE_TEST=ON to build test files.

```linux
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DENABLE_TEST=ON
make -j 8
# Run all tests
make test
# Run specified test
./test/test_sample
```

You can change googletest install path by using -DGTEST_ROOT.

```linux
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DENABLE_TEST=ON -DGTEST_ROOT=${your_install_path}
```

