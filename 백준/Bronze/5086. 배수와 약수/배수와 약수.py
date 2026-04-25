import sys
input = sys.stdin.readline

while True:
    x, y = map(int, input().split())
    if not x and not y:
        break

    if x < y:
        if not y % x:
            print("factor")
        else:
            print("neither")
    
    else:
        if not x % y:
            print("multiple")
        else:
            print("neither")