N = int(input())
M = int(N**0.5)

num = list(range(M+1))
num[1] = 0

for i in num:
    if not i:
        continue
    else:
        for j in range(2*i, M+1, i):
            num[j] = 0
            
prime = [n for n in num if n]

i = 0
n = len(prime)

while True:
    if i == n:
        if N != 1:
            print(N)
        break
    if not N % prime[i]:
        print(prime[i])
        N //= prime[i]
    else:
        i += 1