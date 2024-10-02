#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int fruits[10];

int solve(const vector<int> &A, int N) {
    if (N <= 2) return N;
    
    int ans = 0;
    int l = 0, r = 1;
    fruits[A[l]]++, fruits[A[r]]++;
    int cnt = (A[l] == A[r]) ? 1 : 2;

    while (l != N - 1 || r != N - 1) {
        if (cnt < 3) ans = max(ans, r - l + 1);

        if (cnt < 3 && r != N - 1) {
            r++;
            if (fruits[A[r]]++ == 0) cnt++;
        }
        else if (l != N - 1) {
            if (--fruits[A[l]] == 0) cnt--;
            l++;
        }
    }

    return ans;
}

int main() {
    FastIO

    int N; cin >> N;
    vector<int> A(N);
    for (int &X : A) cin >> X;

    int ans = solve(A, N);
    cout << ans << '\n';
    return 0;
}
