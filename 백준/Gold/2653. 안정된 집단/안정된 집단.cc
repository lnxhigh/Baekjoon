#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 7;

int n;
bool arr[MAX][MAX];
bool vis[MAX];

void dfs(int x, vector<int>& vec) {
    vis[x] = true;
    vec.emplace_back(x);

    for (int nxt = 0; nxt < n; nxt++) {
        if (!arr[x][nxt] && !vis[nxt]) dfs(nxt, vec);
    }
}

int main() {
    FastIO
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    bool chk = true;
    vector<vector<int>> result;

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        
        vector<int> vec;
        dfs(i, vec);
        
        sort(vec.begin(), vec.end());
        result.push_back(vec);

        chk &= (vec.size() > 1u);
        for (int x : vec) {
            for (int y : vec) {
                chk &= !arr[x][y];
            }
        }
    }

    if (!chk) {
        cout << 0 << '\n';
    }
    else {
        sort(result.begin(), result.end());

        int cnt = result.size();
        cout << cnt << '\n';

        for (auto& vec : result) {
            for (auto x : vec) {
                cout << x + 1 << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
