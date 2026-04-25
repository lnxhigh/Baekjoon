N = int(input())

x = len([*str(N)])
s = max(0, N - 9*x)

M = 0
for i in range(s, N):
    if N == i + sum(map(int, str(i))):
        M = i
        break

print(M)
