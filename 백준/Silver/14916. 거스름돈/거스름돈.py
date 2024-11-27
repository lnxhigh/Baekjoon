n = int(input())

INF = n + 1
D = [INF] * (n + 1)
D[0] = 0

for i in range(n + 1):
    for k in [2, 5]:
        if (i >= k):
            D[i] = min(D[i], D[i - k] + 1)

ans = D[n]
print(ans if ans < INF else - 1)
