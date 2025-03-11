N = int(input())
words = [input() for _ in range(N)]
K = int(input())

D = {}

P = [1] * 51
for i in range(1, 51):
    P[i] = P[i - 1] * 36

def score(x):
    return int(x) if x.isdigit() else ord(x) - ord('A') + 10

def dfs(i, cnt):
    if i == 36:
        return 0
    if (i, cnt) in D:
        return D[(i, cnt)]
    
    ret = dfs(i + 1, cnt)
    
    if cnt == K:
        D[(i, cnt)] = ret
        return ret

    add = 0
    target = chr(ord('0') + i) if i < 10 else chr(ord('A') + (i - 10))
    diff = score('Z') - score(target)

    for word in words:
        L = len(word)
        for k in range(L):
            if word[k] == target:
                add += diff * P[L - 1 - k]

    ret = max(ret, dfs(i + 1, cnt + 1) + add)
    D[(i, cnt)] = ret
    return ret

ans = dfs(0, 0)

for word in words:
    L = len(word)
    for k in range(L):
        ans += score(word[k]) * P[L - 1 - k]

def convert(x):
    if x == 0:
        return "0"
    
    res = []
    while x > 0:
        x, rem = divmod(x, 36)
        res.append(chr(ord('0') + rem) if rem < 10 else chr(ord('A') + (rem - 10)))

    return ''.join(res[::-1])

print(convert(ans))
