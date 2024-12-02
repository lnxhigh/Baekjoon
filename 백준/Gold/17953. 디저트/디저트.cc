#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
int A[11][100001];

int main() {
    FastIO
    int N, M; cin >> N >> M;
    for (int i = 0; i < M; i++) 
        for (int day = 0; day < N; day++) 
            cin >> A[i][day];

    vector<int> D(M);
    for (int i = 0; i < M; i++) {
        D[i] = A[i][0];
    }
    
    for (int day = 1; day < N; day++) {
        vector<int> P = D;
        for (int i = 0; i < M; i++) {
            int add = A[i][day];
            for (int k = 0; k < M; k++) {
                if (k != i) D[i] = max(D[i], P[k] + add);
                else D[i] = max(D[i], P[k] + (add >> 1));
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        ans = max(ans, D[i]);
    }
    cout << ans << '\n';
    return 0;
}
