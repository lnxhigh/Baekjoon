#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    string str;

    while (cin >> str, str != ".") {
        int n = str.size();
        vector<int> fail(n);

        for (int i = 1, j = 0; i < n; i++) {
            while (j && str[i] != str[j]) j = fail[j - 1];
            if (str[i] == str[j]) fail[i] = ++j;
        }

        int len = n - fail[n - 1];
        int ans = (n % len == 0) ? n / len : 1;
        cout << ans << '\n';
    }

    return 0;
}
