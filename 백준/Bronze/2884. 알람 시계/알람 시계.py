h, m = map(int, input().split())
if h:
    if m >= 45:
        print(h, m-45)
    else: print(h-1, m-45+60)
else:
    if m >= 45:
        print(h, m-45)
    else:
        print(h-1+24, m-45+60)