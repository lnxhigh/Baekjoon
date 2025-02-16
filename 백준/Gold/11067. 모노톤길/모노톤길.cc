#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<pair<int,int>> data(N);
        map<int, vector<int>> cafe;
        
        for (int i = 0; i < N; i++) {
            int x, y; cin >> x >> y;
            data[i] = { x, y };
            cafe[x].push_back(i);
        }

        int cnt = 0, cur = 0;
        vector<int> result(N);

        for (auto& [x, vec] : cafe) {
            sort(vec.begin(), vec.end(), [&] (const int &i, const int &j) {
                return abs(data[i].second - cur) < abs(data[j].second - cur);
            });
            
            for (int idx : vec) {
                result[cnt++] = idx;
            }
            cur = data[vec.back()].second;
        }

        int M; cin >> M;
        while (M--) {
            int idx; cin >> idx; --idx;
            auto [x, y] = data[result[idx]];
            cout << x << ' ' << y << '\n';
        }
    }
    
    return 0;
}
