#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int64 INF = 1LL << 60;

int64 R, L, B;
vector<int64> X;
vector<int64> D;

// Min budget to build k storage
int64 f(int k) {
    int64 ret = INF;
    for (int i = 1; i + k - 1 <= R; i++) {
        int m = (i + (i + k - 1)) / 2;
        int64 tmp = (k % 2) ? X[m] : 0;

        tmp += D[i + k - 1] - D[m];
        tmp -= D[m] - D[i - 1];
        ret = min(ret, tmp);
    }

    return ret;
}

int besthub(int64 R, int64 L, const vector<int64> &X, int64 B) {
    int ret = 1;
    int low = 1, high = R;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (f(mid) <= B) low = mid + 1, ret = mid;
        else high = mid - 1;
    }

    return ret;
}

int main() {
    FastIO
    cin >> R >> L >> B;
    X.resize(R + 1); D.resize(R + 1);
    for (int i = 1; i <= R; i++) cin >> X[i];
    for (int i = 1; i <= R; i++) D[i] = D[i-1] + X[i];
    
    cout << besthub(R, L, X, B) << '\n';
    return 0;
}
