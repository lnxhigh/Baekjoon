# 2562
import sys

l = []
for num in sys.stdin:
    l.append(int(num))

n0 = l[0]; i0 = 1
i = 0

for n in l:
    i += 1
    if n > n0:
        n0 = n; i0 = i
        
print(n0)
print(i0)