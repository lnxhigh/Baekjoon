def solution(X, Y):
    first = [0] * 10
    second = [0] * 10
    
    for char in X:
        num = ord(char) - ord('0')
        first[num] += 1
    
    for char in Y:
        num = ord(char) - ord('0')
        second[num] += 1
        
    cnt = 0
    ans = ""
    
    for i in range(9, 0, -1):
        m = min(first[i], second[i])
        if m == 0: continue
        
        cnt += m
        char = chr(i + ord('0'))
        ans += char * m
        
    # zero
    zero = min(first[0], second[0])
    
    if cnt == 0:
        return "0" if zero > 0 else "-1"
    
    ans += "0" * zero
    return ans