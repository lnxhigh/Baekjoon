def solution(n, words):
    prev = words[0][0]
    wordList = []
    
    over = False
    for i, word in enumerate(words):
        if over: break
            
        person = i % n + 1
        turn = i // n + 1
        
        if prev[-1] != word[0]:
            over = True
        if word in wordList:
            over = True
        
        wordList.append(word)
        prev = word
        
    if not over:
        person, turn = 0, 0
        
    return [ person, turn ]