#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
const int MAX = 1 << 8;
const int OFFSET = MAX >> 1;

ll A[MAX];
ll grid[MAX][MAX];
int counts[MAX][MAX];
vector<pair<int,int>> xys;

ll gcd(ll x, ll y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

// Find (l, m) such that x / y = 2^l * 3*m
pair<int,int> f(ll x, ll y) {
    ll d = gcd(x, y);
    x /= d; y /= d;

    int two = 0, three = 0;
    
    while (x % 2 == 0) { x /= 2; two++;   }
    while (x % 3 == 0) { x /= 3; three++; }
    while (y % 2 == 0) { y /= 2; two--;   }
    while (y % 3 == 0) { y /= 3; three--; }

    return { two + OFFSET, three + OFFSET};
}

void dfs(int x, int y) {
    counts[x][y]--;
    cout << grid[x][y] << ' ';
    
    // Mul - down / Div - left
    for (int i : { 1, 2 }) {
        int nx = x + dx[i], ny = y + dy[i];
        if (grid[nx][ny] == 0 || counts[nx][ny] == 0) continue;
        dfs(nx, ny);
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A, A + N);
    for (int i = 0; i < N; i++) {
        pair<int,int> p = f(A[i], A[0]);
        int x = p.first, y = p.second;

        grid[x][y] = A[i];
        counts[x][y]++;
        xys.push_back({ x, y });
    }

    sort(xys.begin(), xys.end(), [] (pair<int,int> &left, pair<int,int> &right) {
        return (left.first - left.second) < (right.first - right.second);
    });

    pair<int,int> p = *xys.begin();
    int sx = p.first, sy = p.second;
    dfs(sx, sy);
    
    return 0;
}
