N = int(input())

a = []
for i in range(1, 100):
    a.append(i)

for i in range(1, 10):
    a.append(100*i + 10*i + i)

for d in range(1, 4+1):
    for i in range(1, 10-2*d):
        a.append(100*i + 10*(i+d) + (i+2*d))
    for i in range(2*d, 10):
        a.append(100*i + 10*(i-d) + (i-2*d))

b = [x for x in a if x <= N]
print( len(b) )