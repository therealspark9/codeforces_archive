import sys
input = sys.stdin.buffer.readline
def ri(): return int(input())
def rl(): return list(map(int, input().split()))
def rs(): return input().decode().rstrip('\n\r')

wrt = sys.stdout.write
fastop = lambda *args, end='\n': wrt(' '.join([str(x) for x in args]) + end)
op = print
xrange = lambda *args: reversed(range(*args))
def cdiv(x, y): return (-(-x // y))

enum = enumerate
inf = float('inf')
mod = 10**9 + 7

from collections import defaultdict as dd, Counter, deque
from queue import deque
from heapq import *
from math import gcd
lcm=lambda x,y: x*y//gcd(x,y)

alp = 'abcdefghijklmnopqrstuvwxyz'

Testcase = ri()
for testcase in range(Testcase):
    n, = rl()
    arr = rl()
