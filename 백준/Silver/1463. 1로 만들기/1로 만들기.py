N = int(input())
memo = [0] * (N+1)

for i in range(2, N+1):
    if i % 6 == 0:
        memo[i] = min(memo[i-1]+1, memo[i//2]+1, memo[i//3]+1)
    elif i % 3 == 0:
        memo[i] = min(memo[i-1]+1, memo[i//3]+1)
    elif i % 2 == 0:
        memo[i] = min(memo[i-1]+1, memo[i//2]+1)
    else:
        memo[i] = memo[i-1]+1
        
print(memo[N])