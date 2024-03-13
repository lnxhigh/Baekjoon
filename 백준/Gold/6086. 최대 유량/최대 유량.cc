#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 26*2+1;
const int source = 1, sink = 26;
const int INF = 1000000000;
int E;
int answer;

int graph[N][N] = {0,};
int capacity[N][N] = {0,};
int flow[N][N] = {0,};

// Edmonds-Karp Maximum Flow Algorithm
int maxFlow(int graph[N][N], int capacity[N][N]) {
    int result = 0;
    while (true) {
        int pre[N];
        fill(pre, pre + N, -1);
        
        // BFS
        queue<int> q;
        q.push(source);
        pre[source] = source;
        
        while (not q.empty() and pre[sink] == -1) {
            int cur = q.front();
            q.pop();

            for (int next = 1; next <= N; next++) {
                if (not graph[cur][next]) continue;
                
                if (capacity[cur][next] > flow[cur][next] and pre[next] == -1) {
                    q.push(next);
                    pre[next] = cur;
                }
            }
        }

        // Check if the flow reach sink
        if (pre[sink] == -1) break;

        // Update the flow
        int amount = INF;
        for (int i = sink; i != source; i = pre[i]) {
            amount = min(amount, capacity[pre[i]][i] - flow[pre[i]][i]);
        }
        for (int i = sink; i != source; i = pre[i]) {
            flow[pre[i]][i] += amount;
            flow[i][pre[i]] -= amount;
        }
        result += amount;
    }
    
    return result;
}

int convert(char c) {
    if (c >= 'A' and c <= 'Z') return c - 'A' + 1;
    else if (c >= 'a' and c <= 'z') return c - 'a' + 1 + 26;
    else return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> E;
    for (int e = 0; e < E; e++) {
        char f, t;
        int from, to, c;
        cin >> f >> t >> c;
        
        from = convert(f);
        to = convert(t);

        graph[from][to]++;
        graph[to][from]++;
        capacity[from][to] += c;
        capacity[to][from] += c;
    }

    answer = maxFlow(graph, capacity);
    cout << answer << '\n';

    return 0;
}