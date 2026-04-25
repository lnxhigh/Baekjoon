import sys
input = sys.stdin.readline

a = 1
while a:
    a, b = map(int, input().split())
    if a:
        print(a+b)