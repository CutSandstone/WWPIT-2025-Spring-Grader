#!/usr/bin/env python3

# Argument Order: tc input, file Submission output, correct sol Output
from sys import argv
inp,sub,sol = argv[1:]
sol = open(sol, 'r').read().strip()
sub = open(sub, 'r').read().strip()
assert(sol.split() == sub.split())