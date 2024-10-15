# Simple calc

## Usage

Run the binary with three arguments:
```sh
calc number1 operation number2
```

Numbers could be any decimal real number, e.g. `5` or `-1.2345`.

Operation is one of `+`, `-`, `x`, `/`

### How to build

To build the project, run:
```sh
gcc main.c -o calc
```

### How to build and run with docker

```sh
docker build --tag calc .
docker run calc 2 x 8
```

### How to run unit tests

You need to have CUnit installed.
It's located in `libcunit1-dev` package for debian based Linux distros.

Compile tests:
```sh
gcc test.c -o test-calc -l cunit
```

Run tests:
```sh
./test-calc
```

### How to run e2e tests

Build a docker image, for example `calc:tag`.

Run `e2e-tests.sh` script with the image to test argument:
```sh
./e2e-tests.sh calc:tag
```

