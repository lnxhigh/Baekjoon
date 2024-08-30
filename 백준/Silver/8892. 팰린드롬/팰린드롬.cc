#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

bool IsPalindrome(string str) {
    int L = str.size();
    for (int i = 0; i < L / 2; i++) {
        if (str[i] != str[L-1-i]) return false;
    }
    return true;
}

void solve(int N) {
    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    for (int i = 0; i < N; i++) {
        string &prefix = words[i];
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            
            string &suffix = words[j];
            if (IsPalindrome(prefix + suffix)) {
                string res = prefix + suffix;
                cout << res << '\n';
                return;
            }
        }
    }

    cout << 0 << '\n';
    return;
}

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        solve(N);
    }

    return 0;
}
