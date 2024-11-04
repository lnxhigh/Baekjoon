#include <bits/stdc++.h>
using namespace std;

bool joseph(int n, int k) {
    list<int> people;
    int half = n >> 1;

    for (int i = 0; i < n; i++) {
        people.push_back(i);
    }

    auto iter = people.begin();
    while (n > half) {
        int t = (k - 1) % n;
        while (t--) {
            iter++;
            if (iter == people.end()) {
                iter = people.begin();
            }
        }

        if (*iter < half) {
            return false;
        }

        iter = people.erase(iter);
        if (iter == people.end()) {
            iter = people.begin();
        }
        n--;
    }
    
    return true;
}

int solve(int k) {
    int n = k << 1;
    int m = 0;

    for (m = 1; !joseph(n, m); m++);
    return m;
}

int main() {
    // for (int k = 1; k < 14; k++) {
    //     cout << solve(k) << ' ';
    // }
    //
    
    int ans[14] = { 0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881 };
    while (true) {
        int k; cin >> k;
        if (!k) break;
        cout << ans[k] << '\n';
    }

    return 0;
}
