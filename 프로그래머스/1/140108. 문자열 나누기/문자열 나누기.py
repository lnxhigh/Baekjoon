def solution(s):
    N = len(s)
    cnt, top, size = 0, 0, 0
    
    for i in range(N):
        if not size or s[top] == s[i]:
            size += 1
        else:
            size -= 1
            if not size: 
                top = i+1
                cnt += 1
    
    if size:
        cnt += 1
    return cnt
