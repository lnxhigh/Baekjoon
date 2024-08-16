#include <bits/stdc++.h>
using namespace std;

int TC;

int N;
const int MAX = 1 << 17;
pair<int,int> G[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> TC;

    while (TC--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            int D, I;
            cin >> D >> I;
            G[i] = { D, I };
        }

        sort(G, G + N);

        int res = 0;
        int limit = MAX;
        
        for (int i = 0; i < N; i++) {
            int I = G[i].second;
            if (I < limit) res++;
            limit = min(limit, I);
        }

        cout << res << '\n';
        memset(G, 0, sizeof(G));
    }

    return 0;
}
