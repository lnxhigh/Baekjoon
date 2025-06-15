#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int n, m, d;
priority_queue<tuple<int,int,int>> pq[2];

bool processing[MAX];
int src[MAX], dst[MAX];

int main() {
    FastIO

    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) {
        int x, mi, ri; cin >> x >> mi >> ri;
        pq[x].push({ -ri, -i, -mi });
    }

    int t = 0, cur = 0;

    while (!pq[0].empty() || !pq[1].empty()) {

        // 부품을 기다린다

        if (pq[cur].empty()) {
            // Do nothing
        }
        else if (pq[1 - cur].empty()) {
            auto [ri, i, mi] = pq[cur].top();
            ri = -ri, i = -i, mi = -mi;
            t = max(t, ri);
        }
        else {
            auto [ri, i, mi] = pq[cur].top();
            auto [rio, io, mio] = pq[1 - cur].top();
            ri = -ri, i = -i, mi = -mi, rio = -rio, io = -io, mio = -mio;

            if (t < ri) {
                if (ri <= rio) {
                    t = ri;
                }
                else {
                    t = max(t, rio);
                    t += d, cur = 1 - cur;
                }
            }
        }

        // 부품을 싣는다

        int rem = m;

        while (!pq[cur].empty() && rem > 0) {
            auto [ri, idx, mi] = pq[cur].top();
            ri = -ri, idx = -idx, mi = -mi;

            if (ri > t) break;
            pq[cur].pop();

            if (!processing[idx]) {
                processing[idx] = true;
                src[idx] = t;
            }

            int weight = min(rem, mi);
            rem -= weight, mi -= weight;

            if (mi > 0) pq[cur].push({ -ri, -idx, -mi });
            else if (mi == 0) dst[idx] = t + d;
        }

        // 부품을 옮긴다
        
        t += d;
        cur = 1 - cur;
    }

    for (int i = 0; i < n; i++) {
        cout << src[i] << ' ' << dst[i] << '\n';
    }

    return 0;
}
