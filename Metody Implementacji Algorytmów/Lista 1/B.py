import queue
import sys

VISITED = set()

tests = int(input())
#n, m, x1, y1, x2, y2 = int
for _ in range(tests):
    n, m, x1, y1, x2, y2 = map(int, input().split())
print(type(x1))