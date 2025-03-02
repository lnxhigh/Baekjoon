#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 51, INF = 1 << 30;

int N;
int X[MAX], Y[MAX];
int D[MAX], S[MAX];

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        S[i] = INF;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                D[k] = abs(X[k] - X[i]) + abs(Y[k] - Y[j]);
            }
            sort(D, D + N);
            
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += D[k];
                S[k] = min(S[k], sum);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << S[i] << ' ';
    }
    cout << '\n';
    return 0;
}
