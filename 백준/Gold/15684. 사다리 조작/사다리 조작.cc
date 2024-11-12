#include <bits/stdc++.h>
using namespace std;

int N, M, H;
bool X[32][12];
bool Y[32][12];
vector<pair<int,int>> init;

int go(int k, bool T[32][12]) {
    int x = k;
    for (int i = 1; i <= H; i++) {
        if (T[i][x-1]) x--;
        else if (T[i][x]) x++;
    }
    return x;
}

bool check(bool T[32][12]) {
    for (int k = 1; k <= N; k++) {
        if (go(k, T) != k) return false;
    }
    return true;
}

vector<vector<int>> choose(int n, int k) {
    vector<int> all(n);
    iota(all.begin(), all.end(), 0);

    vector<vector<int>> ret;
    if (n < k) return ret;

    vector<int> bin(n);
    for (int i = 0; i < k; i++) bin[i] = 1;

    do {
        vector<int> sel;
        for (int i = 0; i < n; i++) {
            if (bin[i]) sel.push_back(all[i]);
        }
        ret.push_back(sel);
    } while (prev_permutation(bin.begin(), bin.end()));

    return ret;
}

int solve() {
    if (check(X)) return 0;
    
    vector<pair<int,int>> all;
    for (int row = 1; row <= H; row++) {
        for (int col = 1; col <= N - 1; col++) {
            all.push_back({ row, col });
        }
    }

    for (int k = 1; k <= 3; k++) {
        auto selections = choose((int) all.size(), k);
        for (auto &sel : selections) {

            // check if duplicated
            bool duplicated = false;
            for (int i : sel) {
                auto [a, b] = all[i];
                if (X[a][b]) { duplicated = true; break; }
            }
            if (duplicated) continue;

            // check if valid
            memset(Y, 0, sizeof(Y));
            for (auto [a, b] : init) {
                Y[a][b] = true;
            }

            bool valid = true;
            for (int i : sel) {
                auto [a, b] = all[i];
                if (Y[a][b-1]) { valid = false; break; }
                Y[a][b] = true;
            }
            if (!valid) continue;

            // check i -> i
            if (!check(Y)) continue;

            // return minimum
            return k;
        }
    }

    return -1;
}

int main() {
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        X[a][b] = true;
        init.push_back({ a, b });
    }

    int ans = solve();
    cout << ans << '\n';
    return 0;
}
