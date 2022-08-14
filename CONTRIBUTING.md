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
$ cmake .. -DBUILD_TEST=ON
```

3. Run `ctest`
