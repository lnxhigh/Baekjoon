# 3052
import sys
a = set()
for num in sys.stdin:
    r = int(num) % 42
    a.add(r)

print(len(a))