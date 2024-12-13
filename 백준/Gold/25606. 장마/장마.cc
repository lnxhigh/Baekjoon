#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 17;

int N, M, Q;
int A[MAX];
int S[MAX], D[MAX];
int E[MAX], F[MAX];

int sum(int i) {
    int x = 0;
    while (i) {
        x += F[i];
        i -= i & -i;
    }
    return x;
}

void update(int i, int diff) {
    while (i < MAX) {
        F[i] += diff;
        i += i & -i;
    }
}

int main() {
    FastIO
    cin >> N >> M >> Q;
    
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        S[i] = S[i - 1] + x;

        int cnt = sum(MAX - 1) - sum(i - 1);
        int amt = cnt * M + E[i];
        D[i] = D[i - 1] + amt;
        
        int k = i + x / M;
        update(k, 1);
        E[k + 1] += x % M;
    }

    while (Q--) {
        int x, t; cin >> x >> t;
        if (x == 1) cout << S[t] - D[t] << '\n';
        else if (x == 2) cout << D[t] - D[t - 1] << '\n';
    }
    
    return 0;
}
