import sys
input = sys.stdin.readline

total = int(input())
N = int(input())

price = 0
for i in range(N):
    x, y = map(int, input().split())
    price += x * y

if price == total:
    print("Yes")
else:
    print("No")