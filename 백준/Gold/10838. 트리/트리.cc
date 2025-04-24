#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100001;

int n, k;
int par[MAX];
int col[MAX];
bool chk[MAX];

int find_(int a, int b) {
    int cnt = 0;
    int x = a, y = b;

    while (x != -1 && cnt <= 1000) chk[x] = true, x = par[x], cnt++;
    while (!chk[y]) y = par[y];

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
    unordered_set<int> colors;
    int lca = find_(a, b);
    while (a != lca) colors.insert(col[a]), a = par[a];
    while (b != lca) colors.insert(col[b]), b = par[b];

    return (int) colors.size();
}

int main() {
    FastIO
    cin >> n >> k;
    
    par[0] = -1;

    while (k--) {
        int r; cin >> r;
        if (r == 1) {
            int a, b, c; cin >> a >> b >> c;
            paint_(a, b, c);
        }
        else if (r == 2) {
            int a, b; cin >> a >> b;
            move_(a, b);
        }
        else if (r == 3) {
            int a, b; cin >> a >> b;
            int cnt = count_(a, b);
            cout << cnt << '\n';
        }
    }

    return 0;
}
