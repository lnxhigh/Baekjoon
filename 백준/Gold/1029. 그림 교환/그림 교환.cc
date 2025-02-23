#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 15;

int N;
int A[MAX][MAX];
bool D[1 << MAX][MAX][10];

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char x; cin >> x;
            A[i][j] = (int) (x - '0');
        }
    }

    queue<tuple<int,int,int>> q;
    q.push({ 1, 0, 0 });
    D[1][0][0] = true;

    int ans = 0;

    while (!q.empty()) {
        auto [bits, person, price] = q.front();
        q.pop();

        int cnt = 0;

        for (int i = 0; i < N; i++) {
            if (bits >> i & 1) { cnt++; continue; }
            if (A[person][i] < price) continue;

            int nxt = bits | (1 << i);
            int newPrice = A[person][i];
            if (D[nxt][i][newPrice]) continue;

            q.push({ nxt, i, newPrice });
            D[nxt][i][newPrice] = true;
        }

        ans = max(ans, cnt);
    }

    cout << ans << '\n';
    return 0;
}
