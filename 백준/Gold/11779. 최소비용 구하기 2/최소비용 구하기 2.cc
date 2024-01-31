#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <set>
#define N_MAX 1001
#define M_MAX 100001
#define INF 100000000
using namespace std;
using iPair = pair<int,int>;

int N, M;
int A, B, C;
vector<iPair> graph[N_MAX];
vector<int> city;
int dist[N_MAX];
int predecessor[N_MAX];

void dijkstra(int start) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    for (int i = 0; i <= N; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    pq.push({ 0, start });

    while (not pq.empty()) {
        int cost1 = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost1) continue;
        for (auto s : graph[cur]) {
            int cost2 = s.first;
            int next = s.second;

            if (dist[next] > cost1 + cost2) {
                dist[next] = cost1 + cost2;
                predecessor[next] = cur;
                pq.push({ cost1 + cost2, next });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        graph[A].push_back({ C, B });
    }
    cin >> A >> B;
    
    dijkstra(A);
    cout << dist[B] << '\n';
    
    int last = B;
    vector<int> cities;
    cities.push_back(B);
    while (last != A) {
        last = predecessor[last];
        cities.push_back(last);
    }

    cout << cities.size() << '\n';
    
    for (auto iter = cities.rbegin(); iter != cities.rend(); ++iter) {
        cout << *iter << ' ';
    }
    cout << '\n';
    
    return 0;
}