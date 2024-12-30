#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int K, N;
int A[MAX];
vector<int> D[10];

void input() {
    cin >> K;
    N = (1 << K) - 1;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
}

void dfs(int x, int y, int k) {
    int m = (x + y) / 2;
    D[k].push_back(A[m]);

    if (x == y) return;
    dfs(x, m - 1, k + 1);
    dfs(m + 1, y, k + 1);
}

void print() {
    for (int i = 0; i < K; i++) {
        for (int x : D[i]) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

int main() {
    FastIO
    input();
    dfs(0, N - 1, 0);
    print();
    return 0;
}
