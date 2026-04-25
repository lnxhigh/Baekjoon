import sys
input = sys.stdin.readline

N = int(input())
E = int(input())

# node
class node:
    def __init__(self, value):
        self.value = value # node number
        self.adj = [] # adjacent node list
    
    def link(self, num):
        self.adj.append(num)

# graph
graph = []
for i in range(N+1):
    graph.append(node(i))

for i in range(E):
    [n1, n2] = list(map(int, input().split()))
    graph[n1].link(n2)
    graph[n2].link(n1)


start = 1 # start node
search = [0] * (N+1) # check if you pass the node
search[start] = 1 # 1 if passed

def dfs(start):    
    cnt = 1
    if not graph[start].adj:
        return cnt

    for n in graph[start].adj:
        if not search[n]:
            search[n] = 1
            cnt += dfs(n)

    return cnt

print(dfs(start)-1)