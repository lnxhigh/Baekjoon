import sys
input = sys.stdin.readline
n = int(input())
A = list(map(int, input().split()))

D = A[:]
for i in range(1, n):
    D[i] = max(D[i], D[i - 1] + A[i])

print(max(D))
