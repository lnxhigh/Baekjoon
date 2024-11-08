#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int MAX_N = 250000;
const int MAX_V = (1 << 16) + 2;

int N, K;
int A[MAX_N];
int F[MAX_V];

int sum(int i) {
    int x = 0;
    if (i <= 0) return 0;
    while (i) {
        x += F[i];
        i -= i & -i;
    }
    return x;
}

void update(int i, int diff) {
    while (i < MAX_V) {
        F[i] += diff;
        i += i & -i;
    }
}

int median() {
    int ret = -1;
    int low = 0, high = 65536;
    int L = (K + 1) / 2;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (sum(mid) < L) {
            low = mid + 1, ret = mid;
        }
        else {
            high = mid - 1;
        }
    }

    return ret;
}

int main() {
    FastIO
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    for (int i = 0; i < K; i++) {
        int x = A[i];
        update(x + 1, 1);
    }

    int64 ans = median();
    for (int i = K; i < N; i++) {
        update(A[i] + 1, 1);
        update(A[i - K] + 1, -1);
        ans += (int64) median();
    }

    cout << ans << '\n';
    return 0;
}
