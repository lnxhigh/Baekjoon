#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

bool solve(const vector<int> &H) {
    int sum = 0, two = 0;
    for (int x : H) { sum += x; two += x / 2; }
    if (sum % 3 != 0) return false;
    return two >= (sum / 3);
}

int main() {
    FastIO

    int N; cin >> N;
    vector<int> H(N);
    for (int &h : H) cin >> h;

    string res = solve(H) ? "YES" : "NO";
    cout << res << '\n';
    return 0;
}
