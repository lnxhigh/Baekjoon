N = int(input())

i = 1
answer = [0]
while True:
    if '666' in str(i):
        answer.append(i)
    i += 1
    if len(answer) > 10000:
        break

print(answer[N])
