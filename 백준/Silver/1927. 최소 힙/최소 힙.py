import sys
input = sys.stdin.readline


class heap:
    def __init__(self):
        self.value = [0]

    def insert(self, x):
        self.value.append(x)
        n = len(self.value)-1

        while n != 1:
            if self.value[n//2] > x:
                self.value[n] = self.value[n//2]
                self.value[n//2] = x
                n //= 2
            else:
                break

    def delete(self):
        n = len(self.value) - 2
        if n == -1:
            return 0

        first = self.value[1]
        parent, child = 1, 2
        temp = self.value[n+1]
        
        while child <= n:
            if child < n:
                if self.value[child] > self.value[child+1]:
                    child += 1
            
            if temp < self.value[child]:
                break

            self.value[parent] = self.value[child]
            parent = child
            child *= 2
        
        self.value[parent] = temp
        self.value.pop()
        
        return first

    
N = int(input())
h = heap()

for _ in range(N):
    x = int(input())
    if x:
        h.insert(x)
    else:
        print(h.delete())
