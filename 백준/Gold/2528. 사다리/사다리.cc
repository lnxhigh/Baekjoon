#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 3000;

int N, L;
int l[MAX];
bool d[MAX];

int f(int idx, int t) {
    int len = l[idx];
    bool dir = d[idx];
    
    if (len == L) return len / 2;
    t %= (L - len) * 2;

    if (t >= L - len) t -= L - len, dir ^= true;
    return dir ? (L - len / 2) - t : len / 2 + t;
}

int main() {
    FastIO
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> l[i] >> d[i];
    }

    int t = 0, i = 1;
    while (i < N) {
        int cur = f(i - 1, t), nxt = f(i, t);
        int x = l[i - 1] / 2, y = l[i] / 2;
        bool cross = (max(cur - x, nxt - y) <= min(cur + x, nxt + y));
        cross ? i++ : t++;
    }
    
    cout << t << '\n';
    return 0;
}
