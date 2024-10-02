#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;

    vector<int> S(6);
    for (int &X : S) cin >> X;
    int T, P; cin >> T >> P;

    int cnt = 0;
    for (int &X : S) cnt += (X + T - 1) / T;

    cout << cnt << '\n';
    cout << N / P << ' ' << N % P << '\n';
    return 0;
}
