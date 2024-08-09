#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 1 << 4;
int H[N_MAX], L[N_MAX];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> H[i];

    memset(L, -1, sizeof(L));
    for (int i = 0; i < N; i++) {
        int loc = 0, cnt = 0;
        for (int k = 0; k < N; k++) {
            if (cnt == H[i]) { loc = k; break; }
            if (L[k] == -1 || L[k] > i) cnt++;
        }
        for (int k = loc; k < N; k++) {
            if (L[k] == -1) { L[k] = i; break; }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << L[i] + 1 << ' ';
    }
    cout << '\n';
    return 0;
}
