#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    int N, L; cin >> N >> L;
    priority_queue<pair<int,int>> pq;

    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        pq.push({ -x, i });

        while (!pq.empty()) {
            auto [x, k] = pq.top();
            if (k < i - L + 1) { pq.pop(); continue; }
            else { cout << -x << ' '; break; }
        }
    }

    cout << '\n';
    return 0;
}
