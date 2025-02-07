#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 10005;

int N;
pair<int,int> tree[MAX];

int R = -1;
int P[MAX], H[MAX], S[MAX];

int D[MAX];
vector<int> B[MAX];

int height(int x) {
    if (H[x] != -1) return H[x];
    else if (x == R) return H[x] = 0;
    return H[x] = height(P[x]) + 1;
}

int size(int x) {
    if (x == -1) return 0;
    else if (S[x]) return S[x];
    auto [l, r] = tree[x];

    int cnt = 0;
    cnt += size(l);
    cnt += size(r);
    return S[x] = cnt + 1;
}

void dfs(int x, int s, int e) {
    auto [l, r] = tree[x];
    int k = s + size(l);

    D[x] = k;
    if (l != -1) dfs(l, s, k - 1);
    if (r != -1) dfs(r, k + 1, e);
}

int main() {
    FastIO
    
    cin >> N;
    memset(P, -1, sizeof(P));
    memset(H, -1, sizeof(H));

    for (int i = 0; i < N; i++) {
        int idx, l, r; 
        cin >> idx >> l >> r;
        --idx;
        if (l != -1) l--;
        if (r != -1) r--;
        
        tree[idx] = { l, r };
        if (l != -1) P[l] = idx;
        if (r != -1) P[r] = idx;
    }

    for (int i = 0; i < N; i++) {
        if (P[i] == -1) R = i;
    }
    
    assert(R != -1);
    dfs(R, 0, N - 1);

    for (int i = 0; i < N; i++) {
        B[height(i)].push_back(D[i]);
    }

    for (int i = 0; i < N; i++) {
        if (B[i].empty()) continue;
        sort(B[i].begin(), B[i].end());
    }

    int idx = -1, val = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (B[i].empty()) continue;
        int diff = B[i][B[i].size() - 1] - B[i][0] + 1;
        if (diff >= val) val = diff, idx = i;
    }

    cout << idx + 1 << ' ' << val << '\n';
    return 0;
}
