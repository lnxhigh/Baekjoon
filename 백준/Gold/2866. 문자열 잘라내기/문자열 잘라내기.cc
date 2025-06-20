#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int r, c;
vector<string> arr;
set<string> strs;

int main() {
    FastIO

    // Input

    cin >> r >> c;
    arr.resize(r);
    for (string& str : arr) cin >> str;

    // Init

    for (int i = 0; i < c; i++) {
        string str = "";
        for (int row = r - 1; row >= 0; row--) {
            str.push_back(arr[row][i]);
        }
        strs.insert(str);
    }

    // Solve

    size_t n = c;
    int ans = 0;

    for (int line = 0; line < r; line++) {
        ans++;
        set<string> nxt;
        for (auto str : strs) str.pop_back(), nxt.insert(str);
        strs = move(nxt);
        if (strs.size() < n) { ans--; break; }
    }

    cout << ans << '\n';
    return 0;
}
