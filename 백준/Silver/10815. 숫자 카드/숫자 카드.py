N = int(input())
deck = set(map(int, input().split()))
M = int(input())
cards = list(map(int, input().split()))

for card in cards:
    if card in deck: print(1, end=' ')
    else: print(0, end=' ')