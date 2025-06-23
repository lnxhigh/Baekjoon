n, x, p = map(int, input().split())

scores = []
if n > 0: 
    scores = list(map(int, input().split()))

cnt, same = 0, 0
for score in scores:
    if score > x:
        cnt += 1
    elif score == x:
        same += 1

ans = cnt + 1 if cnt + same < p else -1
print(ans)
