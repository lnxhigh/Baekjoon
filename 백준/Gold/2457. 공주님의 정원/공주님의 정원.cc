#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100005;
using Date = pair<int,int>;

int N;
pair<Date,Date> A[MAX];

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int m, d; 
        cin >> m >> d; 
        Date s = { m, d };
        cin >> m >> d; 
        Date e = { m, d };
        
        A[i] = { s, e };
    }
    sort(A, A + N);
}

int solve() {
    int cnt = 0, idx = 0;
    Date first = { 3, 1 }, last = { 12, 1 };
    Date cur = first, nxt = first;

    while (idx < N) {
        while (idx < N) {
            auto [x, y] = A[idx];
            if (x > cur) break;

            nxt = max(nxt, y);
            idx++;
        }
        if (nxt >= last) return ++cnt;
        if (idx >= N) break;
        
        auto [x, y] = A[idx];
        if (x > nxt) return 0;

        cnt++;
        cur = nxt;
    }
    
    return 0;
}

int main() {
    FastIO
    input();
    int ans = solve();
    cout << ans << '\n';
    return 0;
}
