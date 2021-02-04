# Mars Rover Kata - .NET Starting Point

## Run

### Locally

#### Prerequisites

- .NET SDK (tested with [.NET (Core) 5.0](https://docs.microsoft.com/en-us/dotnet/core/install/)) locally installed

#### Test Execution

In a console from within this directory - where `MarsRoverKata.sln` ist located - just type:

    dotnet test

### Docker

#### Prerequisites

- Docker/[Docker Engine](https://www.docker.com/products/container-runtime)

#### Test Execution

In a console from within this directory - where `MarsRoverKata.sln` ist located - just type:

    docker run --rm -v $(pwd):/app -w /app mcr.microsoft.com/dotnet/sdk:5.0-focal dotnet test

Please note: Standard image `mcr.microsoft.com/dotnet/sdk:5.0` currently - as 
time of writing - has an issue with nuget certificate chaining.

### Docker-Compose

#### Prerequisites

- Docker/[Docker Engine](https://www.docker.com/products/container-runtime)
- [Docker-Compose](https://docs.docker.com/compose/install)

#### Test Execution

In a console from within this directory - where `MarsRoverKata.sln` ist located - just type:

    docker-compose run --rm tests

