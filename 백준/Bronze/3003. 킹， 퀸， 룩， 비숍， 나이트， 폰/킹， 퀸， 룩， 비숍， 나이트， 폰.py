pieces = list(map(int, input().split()))

complete = [1, 1, 2, 2, 2, 8]

for i in range(6):
    print(complete[i] - pieces[i], end=' ')