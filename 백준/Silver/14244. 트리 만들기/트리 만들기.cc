#include <bits/stdc++.h>
using namespace std;

const int MAX = 1 << 6;
vector<int> tree[MAX];

int main() {
    int N; cin >> N;
    int M; cin >> M;
    for (int i = 1; i <= M; i++) {
        tree[0].push_back(i);
        tree[i].push_back(0);
    }

    for (int i = M + 1; i < N; i++) {
        int k = -1;
        for (int i = 0; i < N; i++) {
            if ((int) tree[i].size() == 1) {
                k = i; break;
            }
        }

        tree[i].push_back(k);
        tree[k].push_back(i);
    }

    for (int i = 0; i < N; i++) {
        for (int k : tree[i]) {
            if (i < k) cout << i << ' ' << k << '\n';
        }
    }

    return 0;
}
