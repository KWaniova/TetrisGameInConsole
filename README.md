Setup: https://ddanilov.me/dockerized-cpp-build

docker run -it --rm --name=example \
 --mount type=bind,source=${PWD},target=/src \
 nameofproject/nameofproject_build:0.1 \
 bash

1. make build-docker-deps-image

2. make

3. wejsc do basha: make login
   wejsc do build i odpalic game.out
