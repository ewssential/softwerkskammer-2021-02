FROM ubuntu:focal

ARG UID
ARG GID

RUN groupadd --gid ${GID} kata \
  && useradd --uid ${UID} --gid ${GID} --shell /bin/bash --create-home kata

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update -y \
    && apt-get install -y --no-install-recommends \
        build-essential \
        cmake

USER kata
WORKDIR /home/kata



