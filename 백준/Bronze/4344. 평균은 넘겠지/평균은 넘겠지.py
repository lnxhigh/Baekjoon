# 4344
C = int(input())

def above_avg(case):
    N, *score = list( map(int, case.split()) )
    
    s = sum(score); l = len(score)
    m = s/l
    
    i = 0
    for x in score:
        if x > m:
            i += 1
    
    p = i/l * 100
    
    return p

for i in range(C):
    print("%2.3f%%" % above_avg(input()))