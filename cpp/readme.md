# Mars Rover Kata C++

## Bootstrap

Initialize [googletest](https://github.com/google/googletest) by executing:

    git submodule init
    git submodule update

Below three different modes of operation are outlined:

* _Local Build_
* _Docker Build_
* _Docker Compose_

_Bootstrap_ above is required for all these modes of operation.

Currently the actual tests are implemented in file `mars_rover.test.cpp`

## Local Build

### Prerequisites

* C++17 compiler toolchain
* cmake >= 3.10

### Configure

    ./configure.sh

### Build

    cd build/Debug
    make

### Run Tests

within directory `build/debug` from previous step

    ./kata_tests_run
    
## Docker Build

### Prerequisites

* [Docker Engine](https://docs.docker.com/engine/)

### Build Docker Image

    docker build --build-arg UID=$UID --build-arg GID=$GID -t cppimage .

You may use another Docker image name instead of `cppimage`.

If `$UID` or `$GID` aren't available in your shell environment then you may try
to apply $(id -u) and $(id -g) for them or apply arbitrary values.
The application of `UID` and `GID` attempts to arrange that generated files in 
mounted volumes are created with current user as owner.

### Start Bash in Container

    docker run -it --rm -v $(pwd):/home/kata -u kata cppimage:latest /bin/bash

Apply the Docker image name from previous Docker image build step.

Starts a docker container and opens a shell in interactive mode. Now proceed 
the same way as for _Local Build_:

### Configure

    ./configure.sh

### Build

    cd build/Debug
    make

### Run Tests

within directory `build/debug` from previous step

    ./kata_tests_run

## Docker Compose

Docker Compose facilitates the application of docker above a little bit.
(Refer to local file `docker-compose.yml`.)

### Prerequisites

* [Docker Engine](https://docs.docker.com/engine/)
* [Docker Compose](https://docs.docker.com/compose)

### Start Bash in Container

    UID=${UID} GID=${GID} docker-compose run --rm shell

Continue with step _Configure_ above.

### Cleanup Compose Stack

    UID=${UID} GID=${GID} docker-compose down [--rmi=local]

`--rmi=local` deletes the image(s) built by docker-compose



