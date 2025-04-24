#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100005;
const int MAXQ = 300005;

int n, k;
tuple<int,int,int,int> query[MAXQ];

int par[MAX];
int col[MAX];
bool chk[MAX];
bool chk_col[MAXQ];

void input() {
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int r; cin >> r;
        int a = 0, b = 0, c = 0;

        if (r == 1) cin >> a >> b >> c;
        else if (r == 2) cin >> a >> b;
        else if (r == 3) cin >> a >> b;
        
        query[i] = { r, a, b, c };
    }
}

int find_(int a, int b) {
    int cnt = 0;
    int x = a, y = b;

    // find path

    while (x != -1 && cnt <= 1000) chk[x] = true, x = par[x], cnt++;
    while (!chk[y]) y = par[y];

    // reset to default

    cnt = 0, x = a;
    while (x != -1 && cnt <= 1000) chk[x] = false, x = par[x], cnt++;

    return y;
}

void paint_(int a, int b, int c) {
    int lca = find_(a, b);
    while (a != lca) col[a] = c, a = par[a];
    while (b != lca) col[b] = c, b = par[b];
}

void move_(int a, int b) {
    par[a] = b;
}

int count_(int a, int b) {
    int cnt = 0;
    int lca = find_(a, b);
    int x = a, y = b;

    // count color

    while (x != lca) {
        if (!chk_col[col[x]]) cnt++;
        chk_col[col[x]] = true;
        x = par[x];
    }

    while (y != lca) {
        if (!chk_col[col[y]]) cnt++;
        chk_col[col[y]] = true;
        y = par[y];
    }

    // reset to default

    x = a, y = b;
    
    while (x != lca) {
        chk_col[col[x]] = false;
        x = par[x];
    }

    while (y != lca) {
        chk_col[col[y]] = false;
        y = par[y];
    }

    return cnt;
}

void solve() {

    // initialize
    
    par[0] = -1;

    // compress

    vector<int> colors;
    map<int,int> color_map;

    colors.reserve(MAXQ);
    colors.push_back(0);

    for (const auto& [r, a, b, c] : query) {
        if (r == 1) colors.push_back(c);
    }

    sort(colors.begin(), colors.end());
    colors.erase(unique(colors.begin(), colors.end()), colors.end());
    
    for (int i = 0; i < (int) colors.size(); i++) {
        color_map[colors[i]] = i;
    }

    for (auto& [r, a, b, c] : query) {
        if (r == 1) c = color_map[c];
    }

    // solve

    for (const auto& [r, a, b, c] : query) {
        if (r == 1) paint_(a, b, c);
        else if (r == 2) move_(a, b);
        else if (r == 3) cout << count_(a, b) << '\n';
    }
}

int main() {
    FastIO
    input();
    solve();

    return 0;
}
