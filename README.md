# libmatheng ![build status](https://api.travis-ci.org/SiwonP/libmatheng.svg?branch=master)

This library implements mathematical tools useful, at first, for engineering. 

## Getting Started

### Prerequisites

The library itself doesn't need any library other than the standard C libraries.
However the test suite is built with `criterion`.

#### Test suite prerequisites

##### Packages

If `criterion` is not installed on your machine, you can installed package with
the follwing instruction according to the OS : 
- macOS : `brew install snaipe/soft/criterion`
- AUR : `pacaur -S criterion`
- Debian/Ubuntu : 
```
sudo add-apt-repository ppa:snaipewastaken/ppa
sudo apt-get update
sudo apt-get install criterion-dev
```

##### Binary

Binaries are available [here](https://github.com/Snaipe/Criterion/releases).

##### Build from source

You can still build the criterion library from source as well following thoses
[instructions](http://criterion.readthedocs.io/en/latest/setup.html#installation).

##### More

Please find more information about
[criterion](https://github.com/Snaipe/Criterion) on their official github.


#### Build from source prerequisites

If you happen to want to build this library from the source, you will need `GNU
make 3.81` and `cmake version >= 3.6` as well as a C compiler such as `gcc` or
`clang`.

## Installing

### Packages

There are no packages available yet for the library.

### Binary

There are no binaries available yet of the library.

### Build from source

To build the library from source, please follow the following instructions (on a
UNIX Machine) 

```
git clone https://github.com/SiwonP/libmatheng.git . 
cd libmatheng
mkdir build
cd build
cmake ..
make
```

NB : this library was only tested on macOS so far.

## Running the tests

If this library was built from source, go to your `build` directory and 
```
make test
```

to run the unit tests.

## Authors

- Simon Petit -- initial contributer and only author so far

## License 

This library is under the GNU Lesser General Public License, see
[LICENSE](https://github.com/SiwonP/libmatheng/blob/master/LICENSE) for details.
