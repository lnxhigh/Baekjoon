#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 20;

int N;
int A[MAX];
int D[MAX], P[MAX], R[MAX];

int find(int x) {
    if (x == P[x]) return x;
    return P[x] = find(P[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    else if (x < y) swap(x, y);

    P[x] = y, R[y] += R[x];
    return true;
}

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x; --x;
        A[i] = x, D[x] = i, P[i] = i, R[i] = 1;
    }

    for (int i = 0; i < N - 1; i++) {
        if (D[i] < D[i + 1]) merge(D[i], D[i + 1]);
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt = max(cnt, R[i]);
    }

    cout << N - cnt << '\n';
    return 0;
}
