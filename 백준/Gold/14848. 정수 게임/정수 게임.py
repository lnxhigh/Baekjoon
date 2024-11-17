N, K = list(map(int, input().split()))
A = list(map(int, input().split()))

def gcd(x, y):
    return gcd(y, x % y) if y else x

def lcm(x, y):
    return x * y // gcd(x, y)

ans = 0
for i in range(1 << K):
    mul, sign = 1, 1
    for k in range(K):
        if i >> k & 1:
            mul = lcm(mul, A[k])
            sign = -sign
    
    cnt = N // mul
    ans += sign * cnt
    
print(ans)
