#include <bits/stdc++.h>
using namespace std;

int TC;
enum { Pal, Semi, None };

pair<int,int> check(const string &S, int l, int r) {
    while (l < r) {
        if (S[l] != S[r]) return { l, r };
        l++; r--;
    }
    return { -1, -1 };
}

int solve(const string &S) {
    int L = S.size();
    pair<int,int> p;
    int l, r;
    
    p = check(S, 0, L-1);
    l = p.first, r = p.second;
    if (l == -1 && r == -1) return Pal;

    bool flag = false;
    int newL, newR;

    p = check(S, l+1, r);
    newL = p.first, newR = p.second;
    if (newL == -1 && newR == -1) flag = true;

    p = check(S, l, r-1);
    newL = p.first, newR = p.second;
    if (newL == -1 && newR == -1) flag = true;

    if (flag) return Semi;

    return None;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> TC;
    while (TC--) {
        string S;
        cin >> S;
        cout << solve(S) << '\n';
    }

    return 0;
}
