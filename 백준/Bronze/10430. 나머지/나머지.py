a, b, c = map(int, input().split())
calc = [(a+b)%c, ((a%c) + (b%c))%c, (a*b)%c, ((a%c)*(b%c))%c]
for i in calc:
    print(i)