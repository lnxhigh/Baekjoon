#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int N, M;
const int N_MAX = 1 << 17, M_MAX = 1 << 20;
pair<int,int> P[M_MAX];

int A[N_MAX];
int tree[N_MAX];
int res[N_MAX];

int sum(int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

void update(int i, int diff) {
    while (i <= N) {
        tree[i] += diff;
        i += (i & -i);
    }
}

int find(int nth) {
    int idx = 0, sum = 0;
    if (nth > N) return -1;

    for (int mask = N_MAX; mask > 0; mask >>= 1) {
        int nextIdx = idx + mask;
        if (nextIdx <= N && sum + tree[nextIdx] < nth) {
            sum += tree[nextIdx];
            idx = nextIdx;
        }
    }

    return ++idx;
}

int main() {
    FastIO;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int X, Y; cin >> X >> Y;
        P[i] = { X, Y };
        A[X]++;
    }

    for (int i = 1; i <= N; i++) {
        update(i, 1);
    }

    bool check = true;

    for (int i = 1; i <= N; i++) {
        int k = find(A[i] + 1);
        if (k == -1) { check = false; break; }

        res[i] = k;
        update(k, -1);
    }

    for (int i = 0; i < M; i++) {
        int X = P[i].first, Y = P[i].second;
        if (res[X] <= res[Y]) { check = false; break; }
    }
    
    if (!check) cout << -1;
    else for (int i = 1; i <= N; i++) { cout << res[i] << ' '; }
    cout << '\n';
    
    return 0;
}
