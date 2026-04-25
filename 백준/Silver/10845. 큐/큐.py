import sys
input = sys.stdin.readline


class queue:
    def __init__(self):
        self.value = []

    def push(self, x):
        self.value.append(x)

    def pop(self):
        if not self.value:
            print(-1)
        else:
            print(self.value.pop(0))
    
    def size(self):
        print(len(self.value))

    def empty(self):
        if not self.value:
            print(1)
        else:
            print(0)

    def front(self):
        if not self.value:
            print(-1)
        else:
            print(self.value[0])

    def back(self):
        if not self.value:
            print(-1)
        else:
            print(self.value[-1])

            
def f(q, cmd):
    if cmd[0] == 'push':
        q.push(int(cmd[1]))
    elif cmd[0] == 'pop':
        q.pop()
    elif cmd[0] == 'size':
        q.size()
    elif cmd[0] == 'empty':
        q.empty()
    elif cmd[0] == 'front':
        q.front()
    elif cmd[0] == 'back':
        q.back()
    else:
        print(q.value)
    
    return None


N = int(input())
q = queue()

for i in range(N):
    cmd = input().split()
    f(q, cmd)
            