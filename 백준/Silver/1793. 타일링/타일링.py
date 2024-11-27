MAX = 250 + 1
D = [0] * MAX
D[0] = D[1] = 1

for i in range(2, MAX):
    D[i] = D[i - 1] + D[i - 2] * 2

while True:
    try:
        N = int(input())
        print(D[N])
    except:
        break
