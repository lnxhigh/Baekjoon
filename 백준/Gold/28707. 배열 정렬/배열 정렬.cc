#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

vector<tuple<int,int,int>> op;
unordered_set<string> all;
unordered_map<string, vector<pair<int,string>>> sgraph;

void swap(string &s, int i, int j) {
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}

pair<string, int> transition(string cur, int k) {
    const auto& [l, r, c] = op[k];
    string next = cur;
    swap(next, l, r);
    return { next, c };
}

int main() {
    // Input
    int N; cin >> N;
    
    string init;
    for (int i = 0; i < N; i++) {
        int x; cin >> x; x--;
        init.push_back(x + '0');
    }

    string last = init;
    sort(last.begin(), last.end());

    int M; cin >> M;
    op.resize(M);
    for (int i = 0; i < M; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        op[i] = { --l, --r, c };
    }

    // Pre-process
    queue<string> q;
    q.push(init);
    all.insert(init);

    while (!q.empty()) {
        string cur = q.front();
        q.pop();

        for (int i = 0; i < M; i++) {
            auto [next, cost] = transition(cur, i);
            sgraph[cur].push_back({ cost, next });
            
            if (all.count(next)) continue;
            all.insert(next);
            q.push(next);
        }
    }

    if (!all.count(last)) {
        cout << -1 << '\n';
        return 0;
    }

    N = all.size();
    unordered_map<string,int> index;

    int cnt = 0;
    for (string s : all) {
        index[s] = cnt++;
    }

    vector<vector<pair<int,int>>> graph(N);
    for (string cur : all) {
        for (auto [cost, next] : sgraph[cur]) {
            int i = index[cur], j = index[next];
            graph[i].push_back({ cost, j });
        }
    }

    // dijkstra
    int src = index[init], dst = index[last];
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({ 0, src });
    
    vector<int> dist(N, INF);
    dist[src] = 0;

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (dist[cur] < cost) continue;

        for (auto [weight, next] : graph[cur]) {
            int newCost = cost + weight;
            if (dist[next] > newCost) {
                dist[next] = newCost;
                pq.push({ newCost, next });
            }
        }
    }

    cout << dist[dst] << '\n';
    return 0;
}
