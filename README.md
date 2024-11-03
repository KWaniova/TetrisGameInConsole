# Tetris Game

Project for the abstract programming course at Jagiellonian University 2022/2023

Setup: https://ddanilov.me/dockerized-cpp-build

docker run -it --rm --name=example \
 --mount type=bind,source=${PWD},target=/src \
 nameofproject/nameofproject_build:0.1 \
 bash

1. make build-docker-deps-image

2. make

3. go to bash: make login
   go to build and lounch game.out
