import sys
input = sys.stdin.readline

N, K = map(int, input().split())
coins = []
for _ in range(N):
    coins.append(int(input()))
    
cnt = 0
for coin in reversed(coins):
    if not K:
        break
    if K >= coin:
        cnt += (K // coin)
        K %= coin

print(cnt)