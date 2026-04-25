N, X = map(int, input().split())
seq = map(int, input().split())
seq = filter(lambda x: x < X, seq)
for i in seq: print(i, end = ' ')