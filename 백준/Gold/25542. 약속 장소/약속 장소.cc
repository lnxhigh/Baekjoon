#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int n, len;
vector<string> arr;

bool f(const string& str) {
    bool chk = true;

    for (int i = 0; i < n && chk; i++) {
        int cnt = 0;
        const string& cur = arr[i];

        for (int k = 0; k < len; k++) {
            cnt += (str[k] != cur[k]);
        }

        chk &= (cnt <= 1);
    }

    return chk;
}

string solve() {
    for (int i = 0; i < len; i++) {
        string str = arr[0];

        for (char alpha = 'A'; alpha <= 'Z'; alpha++) {
            str[i] = alpha;
            if (f(str)) return str;
        }
    }
    
    return "CALL FRIEND";
}

int main() {
    FastIO

    cin >> n >> len;
    arr.resize(n);
    for (string& str : arr) cin >> str;

    string ans = solve();
    cout << ans << '\n';

    return 0;
}
