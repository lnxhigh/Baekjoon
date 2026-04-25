import sys
input = sys.stdin.readline

T = int(input())
for i in range(T):
    a, b = map(int, input().split())
    print("Case #{num}: {a} + {b} = {sum}".format(num = i+1, a = a, b = b, sum = a+b))