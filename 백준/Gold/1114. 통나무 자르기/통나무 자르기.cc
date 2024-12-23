#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 10005;

int L, K, C;
int X[MAX], D[MAX];

pair<bool,int> f(int len) {
    int cut = K;
    int last = -1;
    int cur = D[K];
    if (cur > len) return { false, last };

    for (int i = K - 1; i >= 0; i--) {
        int nxt = cur + D[i];
        if (nxt <= len) cur = nxt, cut--;
        else cur = D[i], last = i;
        if (cur > len) return { false, last };
    }

    if (cut < C) last = 0;
    return { cut <= C, last };
}

int main() {
    FastIO
    cin >> L >> K >> C;
    for (int i = 0; i < K; i++) {
        cin >> X[i];
    }
    sort(X, X + K);
    
    D[0] = X[0];
    for (int i = 1; i < K; i++) {
        D[i] = X[i] - X[i - 1];
    }
    D[K] = L - X[K - 1];

    pair<int,int> ans = { L, -1 };
    int low = *min_element(X, X + K), high = L;
    while (low <= high) {
        int mid = (low + high) / 2;
        auto [flag, last] = f(mid);
        if (flag) {
            ans = { mid, last };
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    auto [len, last] = ans;
    int loc = (last != -1) ? X[last] : L;
    cout << len << ' ' << loc << '\n';
    return 0;
}
