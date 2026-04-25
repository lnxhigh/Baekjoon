a, b = map(int, input().split())
calc = [a+b, a-b, a*b, a//b, a%b]
for i in calc:
    print(i)