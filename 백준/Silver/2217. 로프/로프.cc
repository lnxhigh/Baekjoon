#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 1 << 17;
int W[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> W[i];
    sort(W, W + N, [] (int &x, int &y) { return x > y; });

    int res = 0;
    int limit = MAX;
    
    for (int i = 0; i < N; i++) {
        int cnt = i + 1;
        limit = min(limit, W[i]);
        res = max(res, cnt * limit);
    }

    cout << res << '\n';
    return 0;
}
