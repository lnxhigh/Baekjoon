word = input()

for c in range(97, 123):
    print(word.find(chr(c)), end = ' ')