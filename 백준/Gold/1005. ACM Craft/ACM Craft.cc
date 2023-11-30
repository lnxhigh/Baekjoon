#include <iostream>
#include <vector>
#include <queue>
#define N_MAX 1000
using namespace std;

struct Node {
    int index;
    vector<int> to;
    int cost;
};

int T;
int N, K;
int D;
int X, Y;
int W;

int Max (int x, int y) { return x > y ? x : y ; }

int craft() {
    cin >> N >> K;
    Node graph[N_MAX+1];
    int inDegree[N_MAX+1];
    queue<Node> q;
    int city[N_MAX+1];

    for (int i = 1; i <= N; i++) {
        cin >> graph[i].cost;
        graph[i].index = i;
        city[i] = 0;
    }

    for (int i = 1; i <= K; i++) {
        cin >> X >> Y;
        inDegree[Y]++;
        graph[X].to.push_back(Y);
    }
    
    cin >> W;

    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) {
            q.push(graph[i]);
            city[i] = graph[i].cost;
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (q.empty()) {
            cout << "graph has a cycle" << '\n';
            return 0;
        }

        Node x = q.front();
        q.pop();

        for (int k : x.to) {
            city[k] = Max(city[k], city[x.index] + graph[k].cost);

            inDegree[k]--;
            if (inDegree[k] == 0) q.push(graph[k]);
        }
    }

    return city[W];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> T;
    for (int t = 0 ; t < T; t++) {
        cout << craft() << '\n';
    }

    return 0;
}