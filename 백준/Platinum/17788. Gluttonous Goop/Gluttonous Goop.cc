#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 21;

int r, c, k;
vector<string> arr;
long long ans = 0;

int main() {
    FastIO
    cin >> r >> c >> k;
    
    for (int i = 0; i < r; i++) {
        string line; cin >> line;
        arr.push_back(line);
    }

    if (k <= max(r, c)) {
        set<pair<int,int>> xy;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++){
                if (arr[i][j] != '#') continue;

                for (int x = -k; x <= k; x++) {
                    for (int y = -k; y <= k; y++) {
                        xy.insert({ i + x, j + y });
                    }
                }
            }
        }

        ans = (long long) xy.size();
    }
    else {
        set<int> top;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (arr[i][j] == '#') {
                    top.insert(j);
                }
            }

            if (!top.empty()) {
                long long diff = (*top.rbegin() - *top.begin()) + 1;
                long long len = diff + (k * 2);
                ans += len;
            }
        }

        set<int> bottom;

        for (int i = r - 1; i >= 0; i--) {
            for (int j = 0; j < c; j++) {
                if (arr[i][j] == '#') {
                    bottom.insert(j);
                }
            }

            if (!bottom.empty()) {
                long long diff = (*bottom.rbegin() - *bottom.begin()) + 1;
                long long len = diff + (k * 2);
                ans += len;
            }
        }

        if (!top.empty()) {
            long long diff = (*top.rbegin() - *top.begin()) + 1;
            long long len = diff + (k * 2);
            long long cnt = (k * 2) - r;
            ans += len * cnt;
        }
    }

    cout << ans << '\n';

    return 0;
}
