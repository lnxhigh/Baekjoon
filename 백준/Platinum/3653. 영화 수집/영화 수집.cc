#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int sum(int i, vector<int> &F) {
    int x = 0;
    while (i > 0) {
        x += F[i];
        i -= i & -i;
    }
    return x;
}

void update(int i, bool add, vector<int> &F) {
    const int N = (int) F.size();
    int x = add ? 1 : -1;
    while (i < N) {
        F[i] += x;
        i += i & -i;
    }
}

int main() {
    FastIO
    int T; cin >> T;

    while (T--) {
        int N, Q; cin >> N >> Q;
        
        vector<int> X(N + 1); // Location
        for (int i = 1; i <= N; i++) X[i] = N + 1 - i;
        
        vector<int> F(N + Q + 1); // Fenwick Tree
        for (int i = 1; i <= N; i++) update(i, 1, F);
        
        int last = N;

        while (Q--) {
            int i; cin >> i;
            int &before = X[i];
            int after  = ++last;

            int S = sum(before, F);
            cout << N - S << ' ';

            update(before, false, F);
            update(after , true , F);
            before = after;
        }

        cout << '\n';
    }

    return 0;
}
