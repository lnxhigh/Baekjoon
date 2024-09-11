#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N, W;
const int MAX = 1 << 19;
vector<int> tree[MAX];

int main() {
    cin >> N >> W;
    for (int i = 0; i < N-1; i++) {
        int U, V;
        cin >> U >> V;
        tree[U].push_back(V);
        tree[V].push_back(U);
    }

    int cnt = 0;
    for (int i = 2; i <= N; i++) {
        if (tree[i].size() == 1) cnt++;
    }

    double res = (double) W / (double) cnt;
    cout << setprecision(16);
    cout << res << '\n';
    return 0;
}
