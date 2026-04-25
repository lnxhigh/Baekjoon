#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int &X : A) cin >> X;
    sort(A.begin(), A.end());
    int X = A[0] * A[N - 1];
    cout << X << '\n';
    return 0;
}
