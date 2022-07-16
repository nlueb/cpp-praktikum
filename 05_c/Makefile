.PHONY: default run test build_exe build_test init debug

MAKEFLAGS += --no-print-directory

default: test run

run: build_exe
	@echo -e '\x1b[35;1m*** Running Executable\x1b[0m'
	@./build/tasks

test: build_test
	@echo -e '\x1b[35;1m*** Running Tests\x1b[0m'
	@./build/tests --allow-running-no-tests

build_exe: init
	@echo -e '\x1b[35;1m*** Building Executable\x1b[0m'
	@cmake --build build --parallel --target tasks

build_test: init
	@echo -e '\x1b[35;1m*** Building Tests\x1b[0m'
	@cmake --build build --parallel --target tests

init:
	@echo -e '\x1b[35;1m*** Initializing CMake\x1b[0m'
	@cmake -B build -DCMAKE_BUILD_TYPE=Release
	@cmake -B debug -DCMAKE_BUILD_TYPE=Debug

debug: init
	@echo -e '\x1b[35;1m*** Creating debug build\x1b[0m'
	@cmake --build debug --parallel --target tasks
	@cmake --build debug --parallel --target tests
