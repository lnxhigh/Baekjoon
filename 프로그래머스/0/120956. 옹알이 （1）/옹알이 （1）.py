# import re
# def solution(babbling):
#     pattern = r"^(aya|ye|woo|ma)+$"
#     return sum([True if re.match(pattern, s) else False for s in babbling])
import itertools

def solution(babbling):
    words = ["aya", "ye", "woo", "ma"]
    n = len(words)
    allWords = set()
    
    for perm in itertools.permutations(words):
        for bit in range(1 << n):
            subWords = [perm[i] if (1 << i) & bit else "" for i in range(n)]
            allWords.add("".join(subWords))
        
    res = [True if word in allWords else False for word in babbling]
    return sum(res)
