#include <queue>

using namespace std;
const int MAX = 100001;
vector<int> graph[MAX];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    // graph
    
    for (auto road : roads) {
        int x = road[0], y = road[1];
        x--, y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    for (int &source : sources) source--;
    destination--;
    
    // bfs
    
    queue<pair<int,int>> q;
    q.push({ destination, 0 });
    
    vector<int> dist(n, -1);
    vector<bool> vis(n);
    vis[destination] = true;
    
    while (!q.empty()) {
        auto [x, t] = q.front();
        q.pop();
        
        dist[x] = t;
        
        for (int nxt : graph[x]) {
            if (vis[nxt]) continue;
            
            q.push({ nxt, t + 1 });
            vis[nxt] = true;
        }
    }
    
    // distance
    
    vector<int> ans;
    
    for (int x : sources) {
        ans.push_back(dist[x]);
    }
    
    return ans;
}