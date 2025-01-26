#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N, M;
int A[301][21];
int D[301][21], P[301][21];

int dfs(int money, int idx) {
    if (idx < 0) return 0;
    else if (D[money][idx]) return D[money][idx];

    int profit = 0;
    for (int amt = 0; amt <= money; amt++) {
        int value = dfs(money - amt, idx - 1) + A[amt][idx];
        if (value > profit) {
            profit = value;
            P[money][idx] = amt;
        }
    }

    return D[money][idx] = profit;
}

int main() {
    FastIO
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int money; cin >> money;
        for (int idx = 0; idx < M; idx++) {
            cin >> A[money][idx];
        }
    }

    int profit = dfs(N, M - 1);
    cout << profit << '\n';

    stack<int> trace;
    while (M) {
        int amt = P[N][--M];
        trace.push(amt);
        N -= amt;
    }

    while (!trace.empty()) {
        cout << trace.top() << ' ';
        trace.pop();
    }
    cout << '\n';
    return 0;
}
