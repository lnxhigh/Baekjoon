#include <bits/stdc++.h>
using namespace std;

int cnt[26];
int alpha[26];

int main() {
    int N, M; cin >> N >> M;
    string S; cin >> S;

    for (char c : S) {
        int k = c - 'a';
        cnt[k]++;
        alpha[k]++;
    }

    for (int i = 0; i < M; i++) {
        for (int k = 0; k < 26; k++) {
            if (alpha[k] > 0) {
                alpha[k]--;
                break;
            }
        }
    }

    for (char c : S) {
        int k = c - 'a';
        if (alpha[k] == 0) continue;
        if (cnt[k]-- <= alpha[k]) cout << c;
    }
    cout << '\n';
    return 0;
}
