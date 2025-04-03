#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 4;

int N;
pair<int,int> Data[MAX];
bool used[MAX];

vector<int> D;
vector<pair<int,int>> matches;
int ans = 0;

int in(int x) { return x * 2; }
int out(int x) { return x * 2 + 1; }

bool check(vector<pair<int,int>>& match) {
    vector<int> P = D;
    for (auto& [x, y] : match) {
        P[in(x)] = out(y), P[in(y)] = out(x);
    }
    
    queue<int> q;
    vector<int> deg(N * 2);

    // Update degree
    for (int i = 0; i < N * 2; i++) {
        if (P[i] >= 0) deg[P[i]]++;
    }

    // Init queue
    for (int i = 0; i < N * 2; i++) {
        if (deg[i] == 0) q.push(i);
    }

    // Check cycle
    for (int i = 0; i < N * 2; i++) {
        if (q.empty()) return true;

        int x = q.front();
        q.pop();

        int nxt = P[x];
        if (nxt < 0) continue;
        else if (--deg[nxt] == 0) q.push(nxt);
    }

    return false;
}

void dfs(vector<pair<int,int>>& match) {
    int idx = 0;
    while (idx < N && used[idx]) idx++;
    
    if (idx >= N) {
        bool stuck = check(match);
        if (stuck) ans++;
        return;
    }

    used[idx] = true;

    for (int other = idx + 1; other < N; ++other) {
        if (used[other]) continue;
        
        used[other] = true;
        match.push_back({ idx, other });
        dfs(match);
        match.pop_back();
        used[other] = false;
    }
    
    used[idx] = false;
}

int main() {
    FastIO
    cin >> N;
    D = vector<int>(N * 2, -1);

    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        Data[i] = { x, y };
    }

    for (int i = 0; i < N; i++) {
        int inIdx = -1;
        auto [x, y] = Data[i];

        for (int j = 0; j < N; j++) {
            auto [nx, ny] = Data[j];
            if (ny != y || nx <= x) continue;
            if (inIdx == -1 || nx < Data[inIdx].first) inIdx = j;
        }

        // out -> in
        if (inIdx != -1) D[out(i)] = in(inIdx);
    }

    dfs(matches);

    cout << ans << '\n';
    return 0;
}
