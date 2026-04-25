N = int(input())

def factorial(N):
    if N == 0:
        return 1
    else:
        return factorial(N-1) * N
    
print(factorial(N))