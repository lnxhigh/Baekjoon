n = int(input())
mod = 1000000007

x, y, z = 1, 2, 7
for i in range(n):
    w = -x + y + 3 * z
    w = (w + mod) % mod
    x, y, z = y, z, w

print(x)
