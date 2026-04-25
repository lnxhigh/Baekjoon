# 11021
import sys
input = sys.stdin.readline

T = int(input())
for i in range(T):
    a, b = map(int, input().split())
    print("Case #{num}: {sum}".format(num = i+1, sum = a+b))