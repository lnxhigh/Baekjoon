#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 200001;

string S;
int L;
int Q;

int D[26][MAX];

int f(char x) {
    return x - 'a';
}

int query(char x, int l, int r) {
    int ret = D[f(x)][r];
    if (l != 0) ret -= D[f(x)][l - 1];
    return ret;
}

int main() {
    FastIO
    cin >> S;
    L = S.size();
    
    D[f(S[0])][0]++;
    for (int i = 1; i < L; i++) {
        for (char x = 'a'; x <= 'z'; x++) {
            int add = (S[i] == x);
            D[f(x)][i] = D[f(x)][i - 1] + add;
        }
    }

    cin >> Q;
    while (Q--) {
        char x; cin >> x;
        int l, r; cin >> l >> r;
        cout << query(x, l, r) << '\n';
    }
    return 0;
}
