W, H, f, c, x1, y1_, x2, y2 = map(int, input().split())

area = (x2 - x1) * (y2 - y1_)

if f <= W - f:
    area += area * max(min(f, x2) - x1, 0) // (x2 - x1)
else:
    area += area * max(min(W - f, x2) - x1, 0) // (x2 - x1)

ans = W * H - area * (c + 1)
print(ans)
