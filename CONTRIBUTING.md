# Contributing

Issues can be submitted in the GitHub issue tracker. For bugs and enhancements, PRs are welcome.

## Creating a Pull Request

1. Fork the repository
2. Start writing code and committing
3. Create a pull request from the fork into the `develop` branch
4. In the pull request, please reference the issue that the PR is addressing
5. Make sure all checks pass

## Testing

1. Create a build folder and `cd` into it.
2. Run

```text
$ cmake .. -DSVECTOR_BUILD_TEST=ON
```

3. Run `make`.
4. Run `ctest` to run the test suite.

## Examples

1. Create a build folder and `cd` into it.
2. Run

```text
$ cmake .. -DSVECTOR_BUILD_EXAMPLE=ON
```

3. Run `make`.
4. Run

```text
$ ./example/example
```

## Documentation

To build documentation, you need doxygen and sphinx.

1. Build the doxygen documentation.

```text
$ doxygen
```

2. Go into the docs folder and set up a Python environment.

```text
$ cd docs
$ python3 -m venv .venv
$ source .venv/bin/activate
```

3. Install dependencies.

```text
$ pip install -r requirements.txt
```

4. Build the final documentation.

```text
$ make html
```

## Linting and Formatting

To lint your code, you need `clang-tidy` and `clang-format`.

1. Create a build folder and `cd` into it.
2. Run

```text
$ cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
```

3. Run `make`.
4. Go to the root directory of the repository.

```text
$ cd ..
```

5. Run

```text
$ clang-tidy -p build/ scripts/tidy.cpp
$ clang-tidy -p build/ scripts/tidy_class_operators.cpp
```

6. To format your C++ code (do not run the command for any other type of file), run

```text
$ clang-format -i path/to/file/you/just/changed.hpp
```

