import sys
input = sys.stdin.readline

N, M = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(M)]
D = [A[i][0] for i in range(M)]

for day in range(1, N):
    P = D[:]
    for i in range(M):
        L = [ P[k] + A[i][day] if i != k else P[k] + A[i][day] // 2 for k in range(M) ]
        D[i] = max(L)

print(max(D))
