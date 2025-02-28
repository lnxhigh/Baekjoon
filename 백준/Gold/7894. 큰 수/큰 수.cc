#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 10'000'001;
double D[MAX];

int main() {
    FastIO
    int T; cin >> T;

    for (int i = 1; i < MAX; i++) {
        D[i] = D[i - 1] + log10(i);
    }

    while (T--) {
        int N; cin >> N;
        int K = D[N];
        cout << ++K << '\n';
    }
    
    return 0;
}
