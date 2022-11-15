
PROJECT_NAME=nameofproject
DOCKER_DEPS_VERSION=0.1

DOCKER_CC?=clang
DOCKER_CXX?=g++

include build_tools/Makefile


.PHONY: some-target
some-target: 
	@echo "This is the target"