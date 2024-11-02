#include <bits/stdc++.h>
using namespace std;
const int MAX = 1 << 10;
const int INF = 1 << 20;

int N;
string A;
int D[MAX];

int main() {
    cin >> N;
    cin >> A;
    fill(D + 1, D + MAX, INF);

    for (int i = 1; i < N; i++) {
        char cur = A[i];
        char prev = (cur == 'J') ? 'O' : (cur == 'O') ? 'B' : 'J';
        
        for (int k = 0; k < i; k++) {
            if (A[k] == prev) D[i] = min(D[i], D[k] + (i - k) * (i - k));
        }
    }

    int ans = D[N-1];
    if (ans >= INF) ans = -1;
    cout << ans << '\n';
    return 0;
}
