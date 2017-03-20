#!/bin/python

import sys
from itertools import *

def test(a, b, n):
    if n & 1 == 0:
        for i in product(a, b, repeat=n/2):
            yield i
    else:
        for i in product(b, a, repeat=(n/2)+1):
            if i[0] == 'a' or i[0] == 'b':
                yield i[1:]
            else:
                break

a = ['b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z']
b = ['a', 'e', 'i', 'o', 'u']

n = int(raw_input().strip())


for i in (test(a,b, n)):
    print("".join(i))
for i in (test(b,a, n)):
    print("".join(i))
    
