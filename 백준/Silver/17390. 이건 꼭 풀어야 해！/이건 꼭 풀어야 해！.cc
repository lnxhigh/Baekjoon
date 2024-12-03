#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 300003;

int A[MAX];
int S[MAX];



int main() {
    FastIO
    int N, Q; cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    sort(A + 1, A + N + 1);

    for (int i = 1; i <= N; i++) {
        S[i] += S[i - 1] + A[i];
    }

    while (Q--) {
        int L, R; cin >> L >> R;
        int X = S[R] - S[L - 1];
        cout << X << '\n';
    }

    return 0;
}
