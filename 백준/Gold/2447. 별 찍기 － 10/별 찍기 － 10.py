def star(N, i, j):
    if N == 3:
        arr[i-1][j-1] = False
    else:
        for x in range(i - N//6, i + N//6 + 1):
            for y in range(j - N//6, j + N//6 + 1):
                arr[x-1][y-1] = False
        star(N//3, i - N//3, j - N//3)
        star(N//3, i - N//3, j)
        star(N//3, i - N//3, j + N//3)
        star(N//3, i, j - N//3)
        star(N//3, i, j + N//3)
        star(N//3, i + N//3, j - N//3)
        star(N//3, i + N//3, j)
        star(N//3, i + N//3, j + N//3)

N = int(input())
arr = [[True] * N for _ in range(N)]

i = N // 2 + 1
j = N // 2 + 1

star(N, i, j)

for i in range(N):
    for j in range(N):
        if arr[i][j]:
            print('*', end = '')
        else:
            print(' ', end = '')
    print()
