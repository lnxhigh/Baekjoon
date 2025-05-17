#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

string nums[5] = {
    "###...#.###.###.#.#.###.###.###.###.###",
    "#.#...#...#...#.#.#.#...#.....#.#.#.#.#",
    "#.#...#.###.###.###.###.###...#.###.###",
    "#.#...#.#.....#...#...#.#.#...#.#.#...#",
    "###...#.###.###...#.###.###...#.###.###"
};

int n;
string arr[5];

int sums[10];
int counts[10];

bool f(int idx, int x) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][idx * 4 + j] == '#') {
                if (nums[i][x * 4 + j] != '#') {
                    return false;
                }
            }
        }
    }

    return true;
}

double solve() {
    double ret = 0;
    long long mul = 1;

    for (int i = n - 1; i >= 0; i--, mul *= 10LL) {
        double sum = sums[i];
        double cnt = counts[i];
        if (cnt == 0) return -1;
        ret += sum / cnt * mul;
    }

    return ret;
}

int main() {
    FastIO

    cin >> n;
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    for (int idx = 0; idx < n; idx++) {
        for (int x = 0; x < 10; x++) {
            if (f(idx, x)) sums[idx] += x, counts[idx]++;
        }
    }

    double ans = solve();

    cout << setprecision(16);
    if (ans < -0.5) cout << -1 << '\n';
    else cout << ans << '\n';
    
    return 0;
}
