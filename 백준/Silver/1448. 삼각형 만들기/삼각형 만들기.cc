#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 1 << 20;
int A[N_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A, A + N);

    int res = -1;
    for (int i = N-1; i >= 2; i--) {
        bool canMakeTriangle = (A[i] < A[i-1] + A[i-2]);
        if (canMakeTriangle) {
            res = A[i] + A[i-1] + A[i-2];
            break;
        }
    }

    cout << res << '\n';
    return 0;
}
