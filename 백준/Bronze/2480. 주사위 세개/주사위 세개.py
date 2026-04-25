x, y, z = map(int, input().split())

if x == y and y == z:
    ans = 10000 + 1000 * x
elif x == y or y == z or z == x:
    if x == y:
        ans = 1000 + 100 * x
    if y == z:
        ans = 1000 + 100 * y
    if z == x:
        ans = 1000 + 100 * z
else:
    ans = 100 * max(x, y, z)
    
print(ans)