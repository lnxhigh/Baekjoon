#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    int N; cin >> N;
    vector<int> A(N);
    for (int &x : A) cin >> x;
    sort(A.begin(), A.end());
    int m = (N - 1) / 2;
    cout << A[m] << '\n';
    return 0;
}
