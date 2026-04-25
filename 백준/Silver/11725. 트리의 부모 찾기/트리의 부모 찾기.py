import sys
import queue

input = sys.stdin.readline
N = int(input())

tree = []
for i in range(N+1):
    tree.append([])

for i in range(N-1):
    x, y = map(int, input().split())
    tree[x].append(y)
    tree[y].append(x)

parent_of_ = [0] * (N+1)

def findParent(parent):
    q = queue.Queue()
    q.put(parent)
    parent_of_[1] = 1
    
    while not q.empty():
        parent = q.get()
        for child in tree[parent]:
            if not parent_of_[child]:
                q.put(child)
                parent_of_[child] = parent

root = 1
findParent(root)

for i in range(2, N+1):
    print(parent_of_[i])