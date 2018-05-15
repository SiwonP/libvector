# libmatheng

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
- Debian/Ubuntu : ```
sudo add-apt-repository ppa:snaipewastaken/ppa
sudo apt-get update
sudo apt-get install criterion-dev
```

##### Binary

Binaries are available [here]{https://github.com/Snaipe/Criterion/releases}.

##### Build from source

You can still build the criterion library from source as well following thoses
[instructions]{http://criterion.readthedocs.io/en/latest/setup.html#installation}.

##### More

Please find more information about
[criterion]{https://github.com/Snaipe/Criterion} on their official github.


#### Build from source prerequisites

If you happen to want to build this library from the source, you will need `GNU
make 3.81` and `cmake version >= 3.6`.
