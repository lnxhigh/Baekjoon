def solution(s, skip, index):
    alphabet = [chr(i) for i in range(97, 123) if chr(i) not in skip]
    answer = [alphabet[(alphabet.index(i) + index) % len(alphabet)] for i in s]
    return ''.join(answer)