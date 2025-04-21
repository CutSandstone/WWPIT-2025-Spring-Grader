#!/usr/bin/env python3

# Argument Order: tc input, file Submission output, correct sol Output
import sys
a = float(open(sys.argv[2]).read())
b = float(open(sys.argv[3]).read())
assert(abs(a-b) < 1e-4)