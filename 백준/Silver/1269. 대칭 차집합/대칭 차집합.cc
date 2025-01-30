#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int A, B, X; 
unordered_set<int> S;

int main() {
    FastIO
    cin >> A >> B;
    while (A--) cin >> X, S.insert(X);

    int cnt = S.size();
    while (B--) cin >> X, cnt += S.count(X) ? -1 : +1;

    cout << cnt << '\n';
    return 0;
}
