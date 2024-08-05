#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 1 << 8;
int X[N_MAX];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    int init = X[0];
    
    while (true) {
        bool win = true;
        for (int i = 1; i < N; i++) {
            if (X[0] <= X[i]) {
                win = false;
                break;
            }
        }
        if (win) break;

        int maxIdx = -1;
        for (int i = 1; i < N; i++) {
            if (maxIdx == -1 || X[i] > X[maxIdx]) {
                maxIdx = i;
            }
        }

        X[maxIdx]--;
        X[0]++;
    }

    int ans = X[0] - init;
    cout << ans << '\n';
    return 0;
}
