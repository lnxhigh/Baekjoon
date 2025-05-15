#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int n;
int arr[MAX];

int main() {
    FastIO

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        arr[x]++;
    }

    int cnt = n;
    vector<int> res;
    
    while (cnt) {
        for (int i = 0; i < MAX; i++) {
            if (!arr[i]) continue;
            else if (!res.empty() && res.back() == i - 1) continue;

            int x = (arr[i + 1] && arr[i] + arr[i + 1] == cnt) ? i + 1 : i;
            cnt--, arr[x]--;
            res.emplace_back(x);
            break;
        }
    }

    for (int x : res) cout << x << ' ';
    cout << '\n';

    return 0;
}
