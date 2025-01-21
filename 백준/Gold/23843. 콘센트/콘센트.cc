#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N, M;
priority_queue<int> pq;
int D[11];

int main() {
    FastIO
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x; cin >> x; pq.push(x);
    }

    int t = 0;
    int cnt = 0;

    while (true) {
        for (int i = 0; i < M; i++) {
            if (D[i] > 0) {
                D[i]--;
                if (D[i] == 0) cnt++;
            }

            if (D[i] == 0) {
                if (!pq.empty()) {
                    D[i] = pq.top();
                    pq.pop();
                }
            }
        }

        if (cnt >= N) break;
        t++;
    }

    cout << t << '\n';
    return 0;
}
