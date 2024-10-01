#include <bits/stdc++.h>
using namespace std;
const int MAX = 10001, INF = 1 << 20;

vector<tuple<int,int,int>> paths;
int D[MAX];

int main() {
    int N, K; cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int from, to, len; 
        cin >> from >> to >> len;
        if (to > K || len >= to - from) continue;
        auto t = tie(from, to, len);
        paths.push_back(t);
    }
    
    fill(D, D + MAX, INF);
    D[0] = 0;
    
    for (int i = 1; i <= K; i++) {
        D[i] = D[i-1] + 1;
        for (const auto& [ from, to, len ] : paths) {
            if (to == i) D[i] = min(D[i], D[from] + len);
        }
    }
    
    cout << D[K] << '\n';
    return 0;
}
