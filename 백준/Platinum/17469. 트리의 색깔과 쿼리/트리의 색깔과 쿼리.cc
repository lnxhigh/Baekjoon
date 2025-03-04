#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAXN = 100'001;
const int MAXQ = 1'111'111;

int N, Q;
int P[MAXN], C[MAXN];
int X[MAXQ], A[MAXQ];
int Y[MAXQ]; // Answer

int D[MAXN];
set<int> S[MAXN];

int find(int x) {
    if (x == D[x]) return x;
    return D[x] = find(D[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (S[x].size() < S[y].size()) swap(x, y);

    D[y] = x;
    for (int i : S[y]) S[x].insert(i);
    return true;
}

int main() {
    FastIO
    cin >> N >> Q;
    for (int i = 1; i < N; i++) {
        cin >> P[i + 1];
    }
    for (int i = 1; i <= N; i++) {
        cin >> C[i];
        S[i].insert(C[i]);
        D[i] = i;
    }
    
    int L = N - 1 + Q;
    for (int i = 0; i < L; i++) {
        cin >> X[i] >> A[i];
    }

    for (int i = L - 1; i >= 0; i--) {
        if (X[i] == 1) {
            merge(A[i], P[A[i]]);
        }
        else if (X[i] == 2) {
            Y[i] = S[find(A[i])].size();
        }
    }

    for (int i = 0; i < L; i++) {
        if (X[i] == 2) cout << Y[i] << '\n'; 
    }

    return 0;
}
