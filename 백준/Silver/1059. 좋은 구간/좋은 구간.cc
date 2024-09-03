#include <bits/stdc++.h>
using namespace std;

int L;
set<int> S;
int X;

int solve(int X) {
    if (S.count(X)) return 0;

    auto cur  = S.lower_bound(X);
    auto next = S.upper_bound(X);

    int s = *(--cur), e = *next;
    return (X - s) * (e - X) - 1;
}

int main() {
    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> X;
        S.insert(X);
    }
    cin >> X;
    S.insert(0);

    int res = solve(X);
    cout << res << '\n';
    return 0;
}
