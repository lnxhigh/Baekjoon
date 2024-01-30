#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define N_MAX 1001
#define INF 1000000000
using namespace std;
using iPair = pair<int,int>;

int N, M; // N <= 1000, M <= 100000
int A, B, C; // C <= 100000
vector<iPair> graph[N_MAX]; // <cost,to>
int dist[N_MAX];

void dijkstra(int start) {
    priority_queue<iPair,vector<iPair>,greater<iPair>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (not pq.empty()) {
        iPair k = pq.top();
        int cost1 = k.first;
        int cur = k.second;
        pq.pop();
        
        if (dist[cur] < cost1) {
            continue;
        }

        for (iPair s : graph[cur]) {
            int cost2 = s.first;
            int next = s.second;
            if (dist[next] > cost1 + cost2) {
                dist[next] = cost1 + cost2;
                pq.push({ cost1 + cost2, next });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    for (int m = 1; m <= M; m++) {
        cin >> A >> B >> C;
        graph[A].push_back({C, B});
    }
    cin >> A >> B;
    dijkstra(A);
    
    cout << dist[B] << '\n';
    
    return 0;
}