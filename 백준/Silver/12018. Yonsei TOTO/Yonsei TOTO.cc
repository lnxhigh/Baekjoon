#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 7;

int N, M;
int X[MAX];

int main() {
    FastIO
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int P, L; cin >> P >> L;
        vector<int> V(P);
        for (int k = 0; k < P; k++) cin >> V[k];
        sort(V.begin(), V.end());
        if (P >= L) X[i] = V[P - L];
        else X[i] = 1;
    }

    sort(X, X + N);
    
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (M >= X[i]) { cnt++; M -= X[i]; }
    }

    cout << cnt << '\n';
    return 0;
}
