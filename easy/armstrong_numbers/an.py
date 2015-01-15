#!/usr/bin/env python
import sys

with open(sys.argv[1]) as f:
    lines = [l[:-1] for l in f]
    explode = map(list, lines)
    nums = map(int, lines)
    explode_num = map(lambda x: map(int, x), explode)
    pnums = map(lambda x: map(lambda y: y ** len(x), x), explode_num)
    spnums = map(sum, pnums)
    if (len(nums) > 0):
        if spnums[0] == nums[0]:
            sys.stdout.write('True')
        else:
            sys.stdout.write('False')
    for i in range(1, len(nums)):
        if spnums[i] == nums[i]:
            sys.stdout.write('\nTrue')
        else:
            sys.stdout.write('\nFalse')
