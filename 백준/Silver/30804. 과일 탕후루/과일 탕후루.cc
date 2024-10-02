#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int fruits[10];

int solve(const vector<int> &A, int N) {
    if (N <= 2) return N;
    
    int ans = 0;
    int l = 0, r = 1;
    fruits[A[l]]++, fruits[A[r]]++;

    while (l != N - 1 || r != N - 1) {
        int cnt = 0;
        for (int i = 1; i <= 9; i++) {
            if (fruits[i]) cnt++;
        }
        
        if (cnt < 3) ans = max(ans, r - l + 1);

        if (cnt < 3 && r != N - 1) {
            r++;
            fruits[A[r]]++;
        }
        else if (l != N - 1) {
            fruits[A[l]]--;
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
