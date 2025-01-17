#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        vector<pair<int,int>> A(M);
        for (auto& [E, S] : A) {
            cin >> S >> E; --S, --E;
        }
        sort(A.begin(), A.end());

        int cnt = 0;
        vector<bool> D(N);
        for (const auto& [E, S] : A) {
            for (int i = S; i <= E; i++) {
                if (D[i]) continue;
                
                cnt++, D[i] = true;
                break;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
