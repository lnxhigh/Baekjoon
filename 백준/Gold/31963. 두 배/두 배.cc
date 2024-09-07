#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N;
int main() {
    cin >> N;
    int cur; cin >> cur;

    int res = 0;
    for (int i = 0; i < N-1; i++) {
        int next; cin >> next;
        while (cur > next) {
            next <<= 1;
            res++;
        }

        cur = next;
    }

    cout << res << '\n';
    return 0;
}
