#include <bits/stdc++.h>
#define INF 1 << 30
#define N_MAX 1000001
using namespace std;

int N, L = 0;
int A[N_MAX];
int X[N_MAX];
int P[N_MAX];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    A[0] = INF, X[0] = -1;

    for (int i = 1; i <= N; i++) {
        
        // Parametric Search
        int res;
        int start = 1, end = L+1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (A[X[mid]] >= A[i]) {
                res = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        X[res] = i;
        P[i] = X[res-1];
        L = max(L, res);
    }

    // for (int k = X[L]; k != -1; k = P[k]) {
    //     cout << A[k] << ' ';
    // }

    cout << L << '\n';

    return 0;
}
