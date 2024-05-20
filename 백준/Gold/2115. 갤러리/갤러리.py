import sys
input = sys.stdin.readline
m,n = map(int,input().rstrip().split())
l = []
for i in range(m):
    l.append(input().rstrip())

res = 0
dirs = [ (-1, 0), (+1, 0), (0, -1), (0, +1) ] 
isWall = [[[False for _ in range(4)] for _ in range(n)] for _ in range(m)]
occupied = [[[False for _ in range(4)] for _ in range(n)] for _ in range(m)]

for i in range(m):
    for j in range(n):
        if l[i][j] == 'X': continue
        for dir, (dr, dc) in enumerate(dirs):
            isWall[i][j][dir] = (l[i + dr][j + dc] == 'X')
            
for i in range(m):
    for j in range(n):
        for wallDir in range(4): 
            if not isWall[i][j][wallDir] or occupied[i][j][wallDir]: continue
            for dr, dc in dirs:
                r, c = i + dr, j + dc
                if not isWall[r][c][wallDir] or occupied[r][c][wallDir]: continue
                occupied[i][j][wallDir] = occupied[r][c][wallDir] = True
                res += 1

print(res)
