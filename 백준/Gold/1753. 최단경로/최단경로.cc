#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

struct Node {
    int to;
    int weight;

    bool operator> (const Node& other) const {
        return weight > other.weight;
    }
};

int V, E, start;
vector<vector<Node>> graph(20001);
priority_queue<Node, vector<Node>, greater<Node>> pq;
vector<int> dist(20001, INT_MAX);
vector<bool> visited(20001, false);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> V >> E;
    cin >> start;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Node node = { v, w };
        graph[u].push_back(node);
    }

    Node node = { start, 0 };
    pq.push(node);
    dist[start] = 0;
    
    while(not pq.empty()) {
        int now = pq.top().to;
        int weight = pq.top().weight;
        
        pq.pop();
        
        if (visited[now]) continue;
        visited[now] = true;
        
        for(int i = 0; i < graph[now].size(); i++) {
            int cost = weight + graph[now][i].weight;
            if(cost < dist[graph[now][i].to]) {
                dist[graph[now][i].to] = cost;
                Node node = { graph[now][i].to, cost };
                pq.push( node );
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INT_MAX) { cout << "INF" << '\n'; }
        else { cout << dist[i] << '\n'; }
    }

    return 0;
}