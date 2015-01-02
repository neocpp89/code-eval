#!/usr/bin/env python
import sys
# import numpy

with open(sys.argv[1]) as f:
    routes = [l.split(';') for l in f]
    rroute_tups = map(lambda r: map(lambda x: tuple(x.split(',')), r), routes)
    sroute_tups = map(lambda r: filter(lambda x: len(x) == 2, r), rroute_tups)
    route_tups = map(lambda r: map(lambda c: tuple([c[0], int(c[1])]), r), sroute_tups)
    rd = map(lambda r: map(lambda x: x[1], r), route_tups)
    # sr = map(lambda r: sorted(r, key=lambda x: x[1]), route_tups)
    sr = map(lambda r: sorted(r), rd)
    map(lambda r: r.insert(0, 0), sr)
    # d = map(lambda x: numpy.diff(x).tolist(), sr)
    d = sr
    for rr in d:
        for i in range(1, len(rr)):
            rr[i-1] = rr[i] - rr[i-1]
        rr.pop(len(rr)-1)
    sd = map(lambda r: map(lambda c: str(c), r), d)
    sd = map(lambda x: ','.join(x), sd)
    sys.stdout.write('\n'.join(sd))
