#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int MAX = 1 << 7;

int A[MAX];
int64 D[MAX][21];

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    D[0][A[0]] = 1;
    for (int i = 1; i < N - 1; i++) {
        for (int k = 0; k <= 20; k++) {
            if (k + A[i] <= 20) D[i][k + A[i]] += D[i-1][k];
            if (k - A[i] >= 0 ) D[i][k - A[i]] += D[i-1][k];
        }
    }

    cout << D[N-2][A[N-1]];
    return 0;
}
