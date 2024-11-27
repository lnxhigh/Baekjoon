import sys
input = sys.stdin.readline

n = int(input())
A = list(map(int, input().split()))
D = [[A[i], A[i]] for i in range(n)]

if (n > 1):
    D[1] = [ max(A[1], A[0] + A[1]), A[1] ]

for i in range(2, n):
    D[i][0] = max(D[i][0], D[i - 1][0] + A[i])
    D[i][1] = max(D[i][1], D[i - 1][1] + A[i], D[i - 2][0] + A[i])

ans = max(A)
for i in range(n):
    ans = max(ans, D[i][0], D[i][1])

print(ans)