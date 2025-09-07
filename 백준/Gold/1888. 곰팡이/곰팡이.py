from collections import deque

r, c = map(int, input().split())
init = [list(map(int, list(input()))) for _ in range(r)]
minTime = [[0] * c for _ in range(r)]
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def f(x, y):
    ret = 1 << 20

    for i in range(r):
        for j in range(c):
            if not init[i][j]:
                continue
            
            dist = max(abs(x - i), abs(y - j))
            t = dist // init[i][j]
            if dist % init[i][j]: 
                t += 1
            
            ret = min(ret, t)

    return ret

def bfs(x, y, arr, vis):
    q = deque([(x, y)])
    vis[x][y] = True

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if nx < 0 or nx >= r or ny < 0 or ny >= c: 
                continue
            elif vis[nx][ny] or not arr[nx][ny]: 
                continue

            q.append((nx, ny))
            vis[nx][ny] = True

def check(arr):
    cnt = 0
    vis = [[False] * c for _ in range(r)]

    for i in range(r):
        for j in range(c):
            if vis[i][j]:
                continue
            elif arr[i][j]:
                cnt += 1
                bfs(i, j, arr, vis)

    return cnt <= 1

day = 0
update = [row[:] for row in init]

for i in range(r):
    for j in range(c):
        if init[i][j]:
            minTime[i][j] = 0
        else:
            minTime[i][j] = f(i, j)

while (not check(update)):
    day += 1
    for i in range(r):
        for j in range(c):
            update[i][j] = 1 if (update[i][j] > 0 or day >= minTime[i][j]) else 0

print(day)
