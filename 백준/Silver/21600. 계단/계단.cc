#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100005;

int N;
int A[MAX], D[MAX];

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    D[0] = 1;
    for (int i = 1; i < N; i++) {
        if (A[i] > D[i - 1]) D[i] = D[i - 1] + 1;
        else D[i] = A[i];
    }

    int ans = *max_element(D, D + N);
    cout << ans << '\n';
    return 0;
}
