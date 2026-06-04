def solution(k, m, score):
    n = len(score)
    ans = 0
    score.sort(reverse=True)
    
    for i in range(n // m):
        t = 10
        for j in range(m * i, m * (i + 1)):
            t = min(t, score[j])
        ans += t
        
    ans *= m
    return ans
