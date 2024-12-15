#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;
using Point = pair<int,int>;

int N;
pair<int,int> Cows[MAX];
vector<int> X, Y;

int R, C;
int A[MAX][MAX];
int D[MAX][MAX];

void input() {
    cin >> N;
    X.resize(N); Y.resize(N);

    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        Cows[i] = { x, y };
        X[i] = x, Y[i] = y;
    }
}

void compress() {
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    R = X.size();

    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    C = Y.size();

    map<int,int> Xmap, Ymap;
    for (int i = 0; i < (int) X.size(); i++) Xmap[X[i]] = i;
    for (int i = 0; i < (int) Y.size(); i++) Ymap[Y[i]] = i;

    for (int i = 0; i < N; i++) {
        auto [x, y] = Cows[i];
        Cows[i] = { Xmap[x], Ymap[y] };
    }
}

void write() {
    for (int i = 0; i < N; i++) {
        auto [x, y] = Cows[i];
        ++x, ++y;
        A[x][y]++;
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            D[i][j] = D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1] + A[i][j];
        }
    }
}

int f(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) return 0;
    return D[x2][y2] - D[x1 - 1][y2] - D[x2][y1 - 1] + D[x1 - 1][y1 - 1];
}

int solve() {
    int ans = N;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            int Q1 = f(1, 1, i, j);
            int Q2 = f(1, j + 1, i, C);
            int Q3 = f(i + 1, 1, R, j);
            int Q4 = f(i + 1, j + 1, R, C);
            
            int m = max({ Q1, Q2, Q3, Q4 });
            ans = min(ans, m);
        }
    }

    return ans;
}

int main() {
    FastIO
    input();
    compress();
    write();
    int ans = solve();
    cout << ans << '\n';
    return 0;
}
