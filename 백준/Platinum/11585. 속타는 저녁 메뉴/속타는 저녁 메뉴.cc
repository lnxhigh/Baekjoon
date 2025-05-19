#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 21;

int n;
string str, pat;

int cnt = 0;
int fail[MAX];

int main() {
    FastIO

    cin >> n;
    str.resize(n << 1);
    pat.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        str[i + n] = str[i];
    }
    str.pop_back();

    for (int i = 0; i < n; i++) {
        cin >> pat[i];
    }
    
    // Failure function

    for (int i = 1, j = 0; i < n; i++){
        while (j && pat[i] != pat[j]) j = fail[j - 1];
        if (pat[i] == pat[j]) fail[i] = ++j;
    }

    // KMP

    for (int i = 0, j = 0; i < (2 * n - 1); i++) {
        while (j && str[i] != pat[j]) j = fail[j - 1];
        if (str[i] == pat[j]) j++;
        if (j == n) cnt++, j = fail[j - 1];
    }

    int g = gcd(cnt, n);
    int p = cnt / g, q = n / g;
    cout << p << '/' << q << '\n';

    return 0;
}
