#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100005;
const int MAXQ = 300005;

int n, k;
tuple<int,int,int,int> query[MAXQ];

int par[MAX];
int col[MAX];

int t = 0;
int chk[MAXQ];

int find_(int x, int y) {
    int cnt = 0;
    while (x != -1 && cnt <= 1000) chk[x] = t, x = par[x], cnt++;
    while (chk[y] != t) y = par[y];
    
    ++t;
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

    while(a != lca) {
        if (chk[col[a]] != t) cnt++;
        chk[col[a]] = t;
        a = par[a];
    }

    while (b != lca) {
        if (chk[col[b]] != t) cnt++;
        chk[col[b]] = t;
        b = par[b];
    }

    ++t;
    return cnt;
}

int main() {
    FastIO
    cin >> n >> k;
    
    ++t;
    par[0] = -1;
    
    vector<int> vec(k);

    for (int i = 0; i < k; i++) {
        int r; cin >> r;
        int a = 0, b = 0, c = 0;

        if (r == 1) cin >> a >> b >> c;
        else if (r >= 2) cin >> a >> b;

        query[i] = { r, a, b, c };
        vec[i] = c;
    }

    vec.push_back(0);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    for (auto [r, a, b, c] : query) {
        if (r == 1) {
            c = lower_bound(vec.begin(), vec.end(), c) - vec.begin();
            paint_(a, b, c);
        }
        else if (r == 2) {
            move_(a, b);
        }
        else if (r == 3) {
            int cnt = count_(a, b);
            cout << cnt << '\n';
        }
    }

    return 0;
}
