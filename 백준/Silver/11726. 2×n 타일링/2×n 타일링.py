N = int(input())

def fibo(N):
    if N < 2:
        return N
    else:
        arr = [0] * N
        arr[0] = 1
        arr[1] = 2

        for i in range(2, N):
            arr[i] = arr[i-1] + arr[i-2]
        
        return arr[N-1]
    
print(fibo(N) % 10007)