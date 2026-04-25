# 8958
import sys
input = sys.stdin.readline

N = int(input())

def score(case):
    i = 0; total = 0
    for a in case:
        if a == "O":
            i += 1
        else:
            total += i*(i+1)/2
            i = 0
    total += i*(i+1)/2
    return total
    
for _ in range(N):
    print( int( score(input()) ) )