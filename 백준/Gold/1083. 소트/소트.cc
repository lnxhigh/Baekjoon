#include <bits/stdc++.h>
using namespace std;

int N, S;
const int N_MAX = 50;
int A[N_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> S;

    for (int i = 0; i < N; i++) {
        if (S == 0) break;
        int k = i;
        int r = min(N, i+1+S);
        for (int j = i+1; j < r; j++) {
            if (A[j] > A[k]) { k = j; }
        }
        
        S -= k - i;
        int tmp = A[k];
        for (int j = k; j > i; j--) {
            A[j] = A[j-1];
        }
        A[i] = tmp;
    }

    for (int i = 0; i < N; i++) cout << A[i] << ' ';
    cout << '\n';
    return 0;
}
