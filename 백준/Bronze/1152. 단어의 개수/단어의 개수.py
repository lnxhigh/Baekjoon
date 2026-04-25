sentence = input()
word = 1

for c in sentence:
    if c == ' ':
        word += 1

if sentence[0] == ' ':
    word -= 1
if sentence[-1] == ' ':
    word -= 1

print(word)