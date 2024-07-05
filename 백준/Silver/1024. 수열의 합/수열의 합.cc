#include <bits/stdc++.h>
using namespace std;

int N, L;

pair<int,int> solve(int N, int L) {
    if (N*2 == L*(L-1)) return { L, 0 };

    N *= 2;
    int K = floor(sqrt(N));
    int start = -1, res = 1 << 7;

    for (int i = 1; i <= K; i++) {
        if (N % i != 0) continue;
        int x = N / i + i;
        int y = N / i - i;
        if (x % 2 == 0 || y % 2 == 0) continue;

        x = (x-1) / 2;
        y = (y-1) / 2;
        
        int len = x - y;
        if (len < L) continue;
        
        if (len < res) {
            res = len;
            start = y + 1;
        }
    }

    return { res, start };
}

int main() {
    cin >> N >> L;
    pair<int,int> p = solve(N, L);
    int len = p.first, start = p.second;

    if (start < 0 || len > 100) cout << -1;
    else for (int i = start; i < start + len; i++) cout << i << ' ';
    cout << '\n';
    return 0;
}
