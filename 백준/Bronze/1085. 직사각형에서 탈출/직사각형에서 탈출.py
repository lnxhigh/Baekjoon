x, y, w, h = map(int, input().split())
d = min(y, h-y, x, w-x)
print(d)