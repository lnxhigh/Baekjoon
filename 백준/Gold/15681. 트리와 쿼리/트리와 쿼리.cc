#include <bits/stdc++.h>
#define N_MAX 100001
using namespace std;

int N, R, Q;

typedef struct Node {
    int data;
    int parent;
    vector<int> child;
} Node;

Node graph[N_MAX];
bool visited[N_MAX];

void init(int parent) {
    for (int next : graph[parent].child) {
        if (visited[next]) continue;
        visited[next] = true;
        graph[next].parent = parent;
        init(next);
    }
}

int update(int parent) {
    int value = 1;
    for (int next : graph[parent].child) {
        value += update(next);
    }

    return graph[parent].data = value;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> R >> Q;

    for (int i = 0; i < N-1; i++) {
        int U, V;
        cin >> U >> V;
        graph[U].child.push_back(V);
        graph[V].child.push_back(U);
    }

    visited[R] = true;
    graph[R].parent = 0;
    init(R);

    for (int i = 1; i <= N; i++) {
        if (i == R) continue;
        auto pos = find(graph[i].child.begin(), graph[i].child.end(), graph[i].parent);
        graph[i].child.erase(pos);
    }
    
    update(R);

    for (int i = 0; i < Q; i++) {
        int U;
        cin >> U;
        cout << graph[U].data << '\n';
    }

    return 0;
}
