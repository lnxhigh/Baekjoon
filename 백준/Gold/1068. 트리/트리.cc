#include <bits/stdc++.h>
using namespace std;

int N, X, R;
const int N_MAX = 64;
vector<int> tree[N_MAX];
int P[N_MAX];
int D[N_MAX];

int dfs(int parent) {
    if (D[parent] != -1) return D[parent];
    if (tree[parent].empty()) return D[parent] = 1;
    
    int cnt = 0;
    for (int child : tree[parent]) {
        cnt += dfs(child);
    }
    return D[parent] = cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력 처리 및 트리 빌드
    cin >> N;
    for (int i = 0; i <= N-1; i++) {
        int k;
        cin >> k;
        if (k == -1) { R = i; continue; }
        tree[k].push_back(i);
        P[i] = k;
    }
    cin >> X;

    // 루트를 i로 하는 서브트리의 리프 개수 저장
    memset(D, -1, sizeof(D));
    dfs(R);
    
    // 결과 출력
    int ans = D[R] - D[X];
    if (X != R && tree[P[X]].size() <= 1) ans++;
    cout << ans << '\n';
    return 0;
}
