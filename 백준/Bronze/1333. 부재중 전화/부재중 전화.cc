#include <bits/stdc++.h>
using namespace std;

int N, L, D;
const int L_MAX = 1 << 12;
bool canReceive[L_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> L >> D;
    
    fill(canReceive, canReceive + L_MAX, true);
    for (int i = 0; i < N; i++) {
        for (int k = i*(L+5); k < i*(L+5) + L; k++) canReceive[k] = false;
    }

    int ans = L_MAX;
    for (int i = 0; i < L_MAX; i += D) {
        if (canReceive[i]) {
            ans = i;
            break;
        }
    }

    cout << ans << '\n';
    return 0;
}
