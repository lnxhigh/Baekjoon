i = 0
std = [0] * 28

while i < 28:
    std[i] = int(input())
    i += 1
    
std.sort()

n = 1

for x in std:
    if x == n:
        n += 1
    else:
        print(n)
        n += 2
        
while (n <= 30):
    print(n)
    n += 1