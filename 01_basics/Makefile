.PHONY: default run test build init

MAKEFLAGS += --no-print-directory

default: test run

run: build
	@echo -e '\x1b[35;1m*** Running Executable\x1b[0m'
	@./build/tasks

test: build
	@echo -e '\x1b[35;1m*** Running Tests\x1b[0m'
	@./build/tests --allow-running-no-tests

build: init
	@echo -e '\x1b[35;1m*** Building\x1b[0m'
	@cmake --build build --parallel

init:
	@echo -e '\x1b[35;1m*** Initializing CMake\x1b[0m'
	@cmake -B build
