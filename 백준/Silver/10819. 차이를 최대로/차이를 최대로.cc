#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N;
vector<int> A;

int main() {
    FastIO
    cin >> N; A.resize(N);
    for (int &X : A) cin >> X;
    sort(A.begin(), A.end());

    int ans = 0;
    do {
        int diff = 0;
        for (int i = 1; i < N; i++) {
            diff += abs(A[i] - A[i - 1]);
        }
        ans = max(ans, diff);
    } while (next_permutation(A.begin(), A.end()));

    cout << ans << '\n';
    return 0;
}
