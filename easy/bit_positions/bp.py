#!/usr/bin/env python
import sys

def samebit(n, p1, p2):
    a = (n >> (p1-1)) & 0x01
    b = (n >> (p2-1)) & 0x01
    return (a == b)

def tf(b):
    if (b):
        return 'true'
    else:
        return 'false'

with open(sys.argv[1]) as f:
    lines = map(lambda x: map(int,x.split(',')), f)
    b = map(lambda x: samebit(*x), lines)
    s = map(tf, b)
    sys.stdout.write('\n'.join(s))
