# Uneek
`Uneek` is a simple C++ program that takes two read files as input and prints the unique reads in the second file.

## Installation
To install `uneek` 
```
$ git clone repo
$ cd uneek
$ make
```

## Usage
To use `uneek`, run it like this:

```
$ ./uneek file1 file2
```

The output should be a series of lines that are unique to the second file.

## Debugging
`Uneek` can also be built in debug mode by doing the following:
```
$ make debug
```

This enables the built-in print statements to show you the various stages of parsing reads.

## Cleaning
Should you ever need to remove `uneek` you can do so via the following:
```
$ make clean
```

This will remove the executable and any object files.

## Version
Version 1.0

## Contact
Name: Michael Robson

Email: <mprobson@illinois.edu>

Twitter: [@mprobson](https://twitter.com/mprobson)

## License
GNU LGPLv3
