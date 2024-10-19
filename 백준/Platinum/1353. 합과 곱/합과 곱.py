import math
S, P = map(int, input().split())

def solve(S, P):
    if (S == P): 
        return 1
    
    X = -1
    for k in range(int(math.log(P)) + 2, 1, -1):
        if S ** k >= P * k ** k: 
            X = k
    
    return X

print(solve(S, P))
