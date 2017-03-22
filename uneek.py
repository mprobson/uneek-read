#! /usr/bin/env python

import sys

if len(sys.argv) < 3:
    print "You must supply at least two file names: ./uneek.py file1 file2 ..."
    sys.exit(1)

genes = set()

for index in range(1, len(sys.argv)):
    with open(sys.argv[index], 'r') as f:
        for line in f:
            if line[0] == '@':
                continue
            first, second, _ = line.split(None, 2)
            value = int(first[14:].split('#')[0].replace(':', '') + second)

            if index == 1:
                genes.add(value)
            elif value not in genes:
                sys.stdout.write(line)
        
