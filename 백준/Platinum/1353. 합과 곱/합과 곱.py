import math
S, P = map(int, input().split())

# 부동소수점 오류랑 overflow 해결을 위해 파이썬으로 풀이
# 크기가 k 인 리스트가 존재하기 위한 조건을 다음과 같이 추측했다
# S / k >= P ** (1 / k) 

# f(x) = x * P ** (1 / x) 의 최솟값은 x = ln(P) 일 때이므로
# 1 ~ ceil(ln(P)) 까지 조사하면 된다고 생각했다
# 이때 k = 1 일 때만 예외처리

# 이게 안 된다는 것은 또다른 예외가 있다는 건데
# 그렇다면 S / k >= P ** (1 / k) 는 성립하지만 
# k 개의 수로 S 와 P 를 구성하는 경우가 없을 수도 있다는 것인가?
# 그걸 어떻게 증명할 수 있는지 감이 안 온다

def solve(S, P):
    if (S == P): 
        return 1
    
    X = -1
    for k in range(32, 1, -1):
        if S ** k >= P * k ** k: 
            X = k
    
    return X

print(solve(S, P))
