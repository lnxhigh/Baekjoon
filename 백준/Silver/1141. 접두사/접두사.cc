#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N;
const int MAX = 1 << 6;
string words[MAX];

bool IsPrefix(const string &S, const string &T) {
    if (S.size() > T.size()) return false;
    
    int L = S.size();
    for (int i = 0; i < L; i++) {
        if (S[i] != T[i]) return false;
    }
    return true;
}

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    unordered_set<string> all, prefixes;
    for (int i = 0; i < N; i++) {
        all.insert(words[i]);
    }

    for (int i = 0; i < N; i++) {
        for (const string &str : all) {
            if (words[i] == str) continue;

            bool isPrefix = IsPrefix(words[i], str);
            if (isPrefix) prefixes.insert(words[i]);

        }
    }

    int ans = all.size() - prefixes.size();
    cout << ans << '\n';
    return 0;
}
