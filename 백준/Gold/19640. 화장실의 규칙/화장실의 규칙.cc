#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100001;

int N, M, K;
int D[MAX], H[MAX];

int F[MAX];
priority_queue<tuple<int,int,int>> pq;

int main() {
    FastIO
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        cin >> D[i] >> H[i];
        if (i < M) pq.push({ D[i], H[i], -i, });
    }

    int cnt = 0;

    while (!pq.empty()) {
        auto [d, h, x] = pq.top();
        x = -x;
        pq.pop();

        int cur = x + M * F[x];
        if (cur == K) break;
        
        cnt++, F[x]++;
        int nxt = x + M * F[x];
        if (nxt < N) pq.push({ D[nxt], H[nxt], -x });
    }

    cout << cnt << '\n';
    return 0;
}
