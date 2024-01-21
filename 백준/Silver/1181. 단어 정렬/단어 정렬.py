n = int(input())
arr=[str(input()) for i in range(n)]
arr = list(set(arr))
arr.sort()
arr.sort(key = len)
for i in arr:
    print(i)