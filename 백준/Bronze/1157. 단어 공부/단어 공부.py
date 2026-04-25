import sys
input = sys.stdin.readline

word = input().rstrip().upper()

alphabet = dict()
for c in word:
    if c in alphabet:
        alphabet[c] += 1
    else:
        alphabet[c] = 1
        
cnt = 0
for key in alphabet.keys():
    if alphabet[key] == cnt:
        ans = '?'
    elif alphabet[key] > cnt:
        cnt = alphabet[key]
        ans = key
    else:
        continue

print(ans)