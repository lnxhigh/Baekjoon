#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;

int main() {
    int N; cin >> N;
    vector<int64> A(N);
    for (int64 &x : A) cin >> x;
    
    // Median
    sort(A.begin(), A.end());
    int64 median = A[(N-1) / 2];

    // Mean
    int64 sum = accumulate(A.begin(), A.end(), 0LL);
    int64 cnt = N;
    int64 mean = sum / cnt;
    if ((sum % cnt) > (cnt / 2)) mean++;
    
    // Result
    cout << median << ' ' << mean << '\n';
    return 0;
}
