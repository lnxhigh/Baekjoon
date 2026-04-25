import sys
input = sys.stdin.readline

N = int(input())
for i in range(N):
    n, word = input().split()
    for c in word:
        print(c * int(n), end='')
    print('')