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

```txt
$ cmake .. -DSVECTOR_BUILD_TEST=ON
```

3. Run `make` and `ctest`

## Documentation

To build documentation, you need doxygen and sphinx.

1. Build the doxygen documentation

```txt
$ doxygen
```

2. Go into the docs folder and set up a Python environment.

```txt
$ cd docs
$ python3 -m venv .venv
$ source .venv/bin/activate
```

3. Install dependencies

```
$ pip install -r requirements.txt
```

4. Build the final documentation

```
$ make html
```

