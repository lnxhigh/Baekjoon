#include <bits/stdc++.h>
using namespace std;

int T, N;
const int N_MAX = 101;
long long P[N_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    P[1] = P[2] = P[3] = 1;
    P[4] = 2;
    for (int i = 5; i < N_MAX; i++) {
        P[i] = P[i-1] + P[i-5];
    }
    
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << P[N] << '\n';
    }

    return 0;
}
