#include <bits/stdc++.h>
using namespace std;

int TC;
int N, K;
const int N_MAX = 21, K_MAX = 10001;
int A[N_MAX], D[K_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> TC;
    
    while (TC--) {
        memset(A, 0, sizeof(A));
        memset(D, 0, sizeof(D));
        
        cin >> N;
        for (int i = 1; i <= N; i++) { cin >> A[i]; }
        cin >> K;

        D[0] = 1;
        for (int i = 1; i <= N; i++) {
            for (int k = A[i]; k <= K; k++) {
                D[k] += D[k-A[i]];
            }
        }
        
        cout << D[K] << '\n';
    }

    return 0;
}
