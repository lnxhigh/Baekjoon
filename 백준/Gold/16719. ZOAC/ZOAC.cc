#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 7;

int L;
string S;

bool D[MAX];

pair<string,int> choose() {
    set<pair<string,int>> strs;

    for (int i = 0; i < L; i++) {
        if (D[i]) continue;

        string x; x.reserve(L);
        for (int k = 0; k < L; k++) {
            if (D[k] || k == i) x.push_back(S[k]);
        }
        strs.insert({ x, i });
    }

    assert(!strs.empty());
    return *strs.begin();
}

int main() {
    FastIO
    cin >> S;
    L = (int) S.size();

    for (int i = 0; i < L; i++) {
        auto [str, idx] = choose();
        D[idx] = true;
        cout << str << '\n';
    }
    
    return 0;
}
