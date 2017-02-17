#!/bin/python3

import sys
import itertools

n = int(input().strip())
s = input().strip().split(' ')
# your code goes here

def isprefix(a, b):
    return b[:len(a)] == a

def setval(news):
    tot = 0
    for s in news:
        for c in s:
            tot += ord(c)
    return tot

lexos = list(reversed(sorted(s)))
resultset = set(lexos)

i = 0
while True:
    if i >= len(lexos) - 1:
        break
    if lexos[i] not in resultset:
        i += 1
        continue
    j = i + 1
    neighborlength = len(lexos[j])
    while j < len(lexos):
        if isprefix(lexos[j], lexos[i]):
            if lexos[j] in resultset:
                resultset.remove(lexos[j])
            break
        j += 1
    i += 1

print(setval(resultset))

