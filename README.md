# libmatheng

This library implements mathematical tools useful, at first, for engineering. 

## Getting Started

### Prerequisites

The library itself doesn't need any library other than the standard C libraries.
However the test suite is built with `criterion`.

#### Test suite prerequisites

If `criterion` is not installed on your machine, you can installed package with
the follwing instruction according to the OS : 
- macOS : `brew install snaipe/soft/criterion`
- AUR : `pacaur -S criterion`
- Debian/Ubuntu : 
```sudo add-apt-repository ppa:snaipewastaken/ppa
sudo apt-get update
sudo apt-get install criterion-dev```
