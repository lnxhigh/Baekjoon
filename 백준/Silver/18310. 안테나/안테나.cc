#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int &x : A) cin >> x;
    sort(A.begin(), A.end());
    int m = (N - 1) / 2;
    cout << A[m] << '\n';
    return 0;
}
