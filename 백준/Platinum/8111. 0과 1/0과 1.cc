#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<int> pre(n, -1);
        vector<bool> vis(n);
        vector<char> choice(n);

        queue<int> q;
        bool found = false;

        q.push(1 % n);
        vis[1 % n] = true;
        choice[1 % n] = '1';
        
        for (int i = 1; i <= 100 && !found; i++) {
            int cnt = q.size();

            for (int j = 0; j < cnt && !found; j++) {
                int r = q.front();
                q.pop();

                if (r == 0) found = true;
                if (found) break;

                for (int k = 0; k < 2; k++) {
                    int nxt = (10 * r + k) % n;
                    if (vis[nxt]) continue;
                    
                    q.push(nxt);
                    pre[nxt] = r, vis[nxt] = true;
                    choice[nxt] = (char)('0' + k);
                }
            }
        }

        if (found) {
			stack<char> path;
            for (int r = 0; r != -1; r = pre[r]) {
                path.push(choice[r]);
            }

            while (!path.empty()) {
                cout << path.top();
                path.pop();
            }
            cout << '\n';
        }
        else {
            cout << "BRAK" << '\n';
        }
    }

    return 0;
}
