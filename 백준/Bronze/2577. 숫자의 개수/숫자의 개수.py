# 2577
n = 1
for i in range(3):
    n *= int(input())

def count(n, i):
    n = str(n); i = str(i) 
    
    k = 0
    for s in n:
        if s == i:
            k += 1
    
    return k

for i in range(10):
    print(count(n, i))