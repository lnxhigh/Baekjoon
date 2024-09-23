#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 1 << 6;
int F[MAX];

int main() {
    int T; cin >> T;
    
    F[0] = 1, F[1] = 0;
    for (int i = 2; i < MAX; i++) {
        F[i] = F[i-1] + F[i-2];
    }

    while (T--) {
        int N; cin >> N;
        cout << F[N] << ' ' << F[N+1] << '\n';
    }
    
    return 0;
}
