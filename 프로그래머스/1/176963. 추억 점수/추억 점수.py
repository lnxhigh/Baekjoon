def solution(name, yearning, photo):
    answer = []
    
    score = dict()
    N = len(name)
    for i in range(N):
        score[name[i]] = yearning[i]
    
    for photo_ in photo:
        res = 0
        for person in photo_:
            if not person in score:
                continue
            res += score[person]
        answer.append(res)
    
    return answer