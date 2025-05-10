#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int n, m;
priority_queue<pair<int,int>> pq;

int main() {
    FastIO
    cin >> n >> m;

    for (int i = 1; i < 2 * m; i++) {
        int x; cin >> x;
        pq.push({ x, i });
    }

    for (int i = m; i <= n - m + 1; i++) {
        int mn = i - (m - 1), mx = i + (m - 1);

        while (!pq.empty() && (pq.top().second < mn || pq.top().second > mx)) pq.pop();
        if (!pq.empty()) cout << pq.top().first << ' ';
        
        if (i < n - m + 1) {
            int x; cin >> x;
            pq.push({ x, i + m });
        }
    }

    return 0;
}
