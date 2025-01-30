#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100001;

int N, K;
int ID[MAX], W[MAX];
pair<int,int> D[MAX];

int main() {
    FastIO
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> ID[i] >> W[i];
    }

    set<int> counter;
    for (int i = 0; i < K; i++) counter.insert(i);

    long long ans = 0;
    int idx = 0, cnt = 0;

    while (idx < N || cnt < N) {
        for (int x : counter) {
            if (idx >= N) break;
            D[x] = { ID[idx], W[idx] };
            counter.erase(x);
            idx++;
        }

        int t = 1 << 10;
        for (int x = 0; x < K; x++) {
            auto& [id, w] = D[x];
            if (w != 0) t = min(t, w);
        }

        for (int x = K - 1; x >= 0; x--) {
            auto& [id, w] = D[x];
            if (w == 0) continue;
            
            w -= t;
            if (w == 0) {
                cnt++;
                counter.insert(x);
                ans += (long long) cnt * id;
                id = 0;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
