#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 1 << 10;
int P[MAX], D[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> P[i];    
    
    for (int i = 1; i <= N; i++) {
        for (int j = i; j > 0; j--) {
            D[i] = max(D[i], D[i-j] + P[j]);
        }
    }

    cout << D[N] << '\n';
    return 0;
}
