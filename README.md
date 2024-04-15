# MTZPZ lab 2
This console application converts Markdown files into HTML or ANSI fragments. The generated HTML or ANSI markup can be output to standard output (stdout) or written to an output file if provided with the --out argument. Additionally, the application performs checks for common Markdown errors, such as nested or unbalanced markup tags. If it encounters incorrect Markdown due to nesting issues or unbalanced tags, it will output an error to the standard error (stderr) and terminate with a non-zero exit code.

The output format can be specified using the --format argument, with options being html for HTML format or ansi for ANSI format. If the --format argument is not provided, the default output format will be HTML.

## Prerequisites:
Does not support Cyrillic

## Installation
Clone the repository from GitHub:

```git clone https://github.com/Ancellie/labMTZPZ-2.git```

```cd labMTZPZ-2```

## Usage
Use exe file:
Enter the command to start the program:

```./labMTZPZ-2.exe inputFile [--out outputFile] [--format html/ansi]```

Examle:

```./labMTZPZ-2.exe example.txt --out output.html --format ansi```

## How to run tests
```./tests.exe```

# Tests failed
https://github.com/Ancellie/labMTZPZ-2/actions/runs/8691192555/job/23832844537

# Revert commit
[https://github.com/Ancellie/labsMTZPZ/commit/2f52ba405c10b608510ae4f03d0700f19ea017c2](https://github.com/Ancellie/labMTZPZ-2/commit/e2175d9d62d3ff94e93c45295ef7803ca7d50e60)

# Did unit-tests help
In general, the tests helped to find one important error, which I then corrected in 1 lab. They also help enough when correcting errors that could arise, because it is much easier to run tests than to check each item
