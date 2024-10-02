#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        
        deque<pair<int,int>> dq;
        for (int i = 0; i < N; i++) {
            int X; cin >> X;
            dq.push_back({ i, X });
        }

        vector<int> res;

        while (!dq.empty()) {
            const auto [ front, priority ] = dq.front();

            bool print = true;
            for (const auto& [ i, X ] : dq) {
                if (X > priority) {
                    dq.pop_front();
                    dq.push_back({ front, priority });
                    print = false;
                    break;
                }
            }

            if (!print) continue;
            res.push_back(front);
            dq.pop_front();
        }
        
        int ans = -1;
        for (int i = 0; i < N; i++) {
            if (res[i] == M) {
                ans = i;
                break;
            }
        }

        cout << ++ans << '\n';
    }

    return 0;
}
