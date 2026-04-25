#include <bits/stdc++.h>
using namespace std;

int N;

int query(int i) {
    cout << "Q " << i << endl;
    int j; cin >> j;
    return j;
}

int solve() {
    vector<int> v(N);
    iota(v.begin(), v.end(), 1);
    random_device rd;
    default_random_engine engine(rd());
    shuffle(v.begin(), v.end(), engine);

    unordered_set<int> s;
    for (int i : v) s.insert(i);

    while (!s.empty()) {
        int x = *s.begin();
        int y = query(x);
        if (x == y) return x;
        s.erase(x); s.erase(y);
    }
    
    return -1;
}

int main(int argc, char **argv) {
    int T;
    cin >> N >> T;

    for (int i = 0; i < T; i++) {
        int res = solve();
        cout << "A " << res << endl;

        char verdict; cin >> verdict;
        if (verdict == 'W') exit(0);
    }
    return 0;
}
