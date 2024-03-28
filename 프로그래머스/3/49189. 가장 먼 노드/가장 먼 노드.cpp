#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#define N_MAX 20001
#define INF 10000000
using namespace std;

vector<int> graph[N_MAX];
priority_queue<pair<int,int>> pq;

int dist[N_MAX];

void dijkstra(int start) {
    for (int i = 1; i <= N_MAX; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    
    pq.push({ start, 0 });
    while (not pq.empty()) {
        int cur = pq.top().first;
        int cost = -pq.top().second;
        pq.pop();
        
        if (dist[cur] < cost) continue;
        
        for (int next : graph[cur]) {
            if (dist[next] > cost + 1) {
                dist[next] = cost + 1;
                pq.push({ next, -dist[next] });
            }
        }
    }
}

int solution(int n, vector<vector<int>> edges) {
    for (vector<int> edge : edges) {
        int from = edge[0];
        int to = edge[1];
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
   
    int start = 1;
    dijkstra(start);
    
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
    
    int m = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > m) m = dist[i];
    }
    
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (m == dist[i]) answer++;
    }
    
    return answer;
}