#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100001;

int N, M, K;
int D[MAX], H[MAX];

int F[MAX];
priority_queue<tuple<int,int,int,int>> pq;

int main() {
    FastIO
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        cin >> D[i] >> H[i];
        if (i < M) pq.push({ D[i], H[i], -i, i });
    }

    int cnt = 0;

    while (!pq.empty()) {
        auto [d, h, line, num] = pq.top();
        line = -line;
        pq.pop();
        
        if (num == K) break;
        
        cnt++;
        F[line]++;

        int nxt = line + M * F[line];
        if (nxt < N) pq.push({ D[nxt], H[nxt], -line, nxt });
    }

    cout << cnt << '\n';
    return 0;
}
