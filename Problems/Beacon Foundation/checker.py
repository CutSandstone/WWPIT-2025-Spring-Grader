#! /usr/bin/env python3

# Argument Order: tc input, file Submission output, correct sol Output
from sys import argv
inp,sub,sol = argv[1:]
sol = [*map(int,open(sol, 'r').read().strip().split())]
sub = [*map(int,open(sub, 'r').read().strip().split())]
sol.sort()
sub.sort()
assert(sol==sub)