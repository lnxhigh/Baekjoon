import math
n = int(input())
print(*map(lambda x: math.comb(2*x, x) // (x+1), [n+1]))