def solution(s):
    answer = 0
    stack = []
    
    for c in s:
        if not stack or stack[-1] == c:
            stack.append(c)
        else:
            stack.pop()
            if not stack: 
                answer += 1
    
    if stack:
        answer += 1
        
    return answer
