#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 200'001;

int n, m;
vector<int> arr[MAX];
bool infection[MAX];

set<int> ppl;
bool res[MAX];

int main() {
    FastIO

    // Input

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        arr[i].emplace_back(i);
    }

    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        arr[i + n].resize(k);
        for (int& x : arr[i + n]) cin >> x, x--;
    }

    for (int i = 0; i < n; i++) {
        cin >> infection[i];
    }

    // Solve

    for (int i = n + m - 1; i >= 0; i--) {
        bool chk = true;
        for (int x : arr[i]) {
            if (!infection[x]) chk = false;
            if (ppl.count(x)) chk = false;
        }

        for (int x : arr[i]) {
            if (chk) res[x] = true;
            else ppl.insert(x);
        }
    }
    
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (res[i] ^ infection[i]) flag = false;
    }

    if (flag) {
        cout << "YES" << "\n";
        for (int i = 0; i < n; i++) {
            int k = ppl.count(i) ? 0 : 1;
            cout << k << ' ';
        }
        cout << '\n';
    }
    else {
        cout << "NO" << "\n";
    }

    return 0;
}
