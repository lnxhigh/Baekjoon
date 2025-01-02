#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 5005;

int N;
int A[MAX], D[MAX];

int dfs(int i) {
    if (D[i] != -1) return D[i];

    int cnt = 0;
    for (int j = i + 1; j < N; j++) {
        if (A[j] % A[i] == 0) {
            cnt = max(cnt, dfs(j));
        }
    }
    
    return D[i] = ++cnt;
}

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    sort(A, A + N);
    memset(D, -1, sizeof(D));

    int ans = N;
    for (int i = 0; i < N; i++) {
        ans = min(ans, N - dfs(i));
    }

    cout << ans << '\n';
    return 0;
}
