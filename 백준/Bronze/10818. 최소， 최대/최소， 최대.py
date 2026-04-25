import sys
input = sys.stdin.readline
N = int(input())
Nlist = list(map(int, input().split()))

n_min = n_max = Nlist[0]

for n in Nlist:
    if n < n_min:
        n_min = n
    if n > n_max:
        n_max = n

print(n_min, n_max)