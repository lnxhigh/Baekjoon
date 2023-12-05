#include <iostream>
#include <queue>
#define N_MAX 1001
#define INF 2147483647
using namespace std;

struct Node {
    int to;
    int weight;
    bool operator> (const Node& other) const {
        return weight > other.weight;
    }
};

int N, M, X;
int S, E, T;

vector<vector<Node>> graphX(N_MAX); // X -> i ( 1 <= i <= N )
vector<vector<Node>> graphN(N_MAX); // i -> X ( 1 <= i <= N )
priority_queue<Node, vector<Node>, greater<Node>> pq;

bool visited[N_MAX];
int distX[N_MAX], distN[N_MAX];

int ans = 0;
int Max(int x, int y) { return x > y ? x : y ; }

void input() {
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        cin >> S >> E >> T;
        graphX[S].push_back({ E, T });
        graphN[E].push_back({ S, T });
    }
}

void initialize(bool visited[], int dist[]) {
    for (int i = 1; i <= N; i++) {
        visited[i] = false;
        dist[i] = INF;
    }
}

void dijkstra (int start, vector<vector<Node>>& graph, int dist[]) {
    Node node = { start, 0 };
    pq.push(node);
    dist[start] = 0;
    
    while(not pq.empty()) {
        int now = pq.top().to;
        int weight = pq.top().weight;
        
        pq.pop();
        
        if (visited[now]) continue;
        visited[now] = true;
        
        int s = graph[now].size();
        for(int i = 0; i < s; i++) {
            int cost = weight + graph[now][i].weight;
            if(cost < dist[graph[now][i].to]) {
                dist[graph[now][i].to] = cost;
                Node node = { graph[now][i].to, cost };
                pq.push( node );
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    input();
    
    initialize(visited, distX);
    dijkstra(X, graphX, distX);
    
    initialize(visited, distN);
    dijkstra(X, graphN, distN);
    
    for (int i = 1; i <= N; i++) {
        ans = Max(ans, distX[i] + distN[i]);
    }
    cout << ans << '\n';

    return 0;
}