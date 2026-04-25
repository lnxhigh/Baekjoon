N = int(input())

def fibo(N):
    if N <= 1:
        return N
    else:
        return fibo(N-1) + fibo(N-2)
    
print(fibo(N))