def solution(answers):
    correct = [0, 0, 0]
    patterns = ["12345", "21232425", "3311224455"]
    
    for idx, answer in enumerate(answers):
        for num in range(3):
            pattern = patterns[num]
            n = len(pattern)
            guess = ord(pattern[idx % n]) - ord('0')
            
            if guess == answer:
                correct[num] += 1
    
    m = max(correct)
    return [idx + 1 for idx, x in enumerate(correct) if x == m]
