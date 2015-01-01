#!/usr/bin/env python
import sys

def is_palindrome(n):
    s = str(n)
    return (s == s[::-1])

def reverse_and_add(starting, maxit=100):
    iters = 0
    n = starting
    while (iters <= maxit):
        if is_palindrome(n):
            break
        else:
            n += int(str(n)[::-1])
        iters += 1

    return (iters, n) 

with open(sys.argv[1]) as f:
    nums = map(int, f)
    p = map(reverse_and_add, nums)
    for t in p:
        print t[0], t[1]
