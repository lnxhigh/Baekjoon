import sys
input = sys.stdin.readline
MOD = 1000000009

def mul(a, b):
    r = len(a)
    c = len(b[0])
    s = len(b)

    res = [[0]*c for _ in range(r)]
    for i in range(r):
        for j in range(c):
            for k in range(s):
                res[i][j] += a[i][k] * b[k][j]
                res[i][j] %= MOD

    return res

def eye(n):
    res = [[0]*n for _ in range(n)]
    for i in range(n):
        res[i][i] = 1
    return res

def power(m, p):
    if p == 0:
        n = len(m)
        return eye(n)
    
    elif p == 1:
        return m
    
    x = power(m, p//2)
    x = mul(x, x)

    if p % 2 == 0:
        return x
    else:
        return mul(m, x)

m = [[1, 1, 1], [1, 0, 0], [0, 1, 0]]
x = [[4], [2], [1]]

T = int(input())
for _ in range(T):
    N = int(input())
    print(*mul(power(m, N-1), x)[-1])
