N_MAX = 5000
primeList = [True] * (N_MAX+1)
primeList[0] = primeList[1] = False

def sieve(N):
    for i in range(N+1):
        if not primeList[i]: 
            continue
        for j in range(i*2, N, i):
            primeList[j] = False

def solution(nums):
    sieve(N_MAX)
    
    answer = 0
    n = len(nums)
    
    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                sum = nums[i] + nums[j] + nums[k]
                if (primeList[sum]):
                    answer += 1

    return answer