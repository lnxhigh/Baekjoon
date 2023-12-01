#include <iostream>
#define N_MAX 100001
using namespace std;

struct Node {
    int to;
    bool visited = false;
    int start;
    int end;
    int group;
};

int T;

void dfs(int i, int depth, Node graph[], int group) {
    graph[i].visited = true;
    graph[i].start = depth;
    graph[i].end = depth;
    graph[i].group = group;

    int to = graph[i].to;
    if (not graph[to].visited) {
        dfs(to, depth+1, graph, group);
    }
    else {
        if (group == graph[to].group) {
            graph[to].end = depth+1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        Node graph[N_MAX];

        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> graph[i].to;
        }
        
        int group = 0;
        for (int i = 1; i <= N; i++) {
            if (not graph[i].visited) {
                int depth = 0;
                dfs(i, depth, graph, ++group);
            }
        }
        
        int answer = 0;
        for (int i = 1; i <= N; i++) {
            answer += graph[i].end - graph[i].start;
        }
        answer = N - answer;
        cout << answer << '\n';
    }

    return 0;
}