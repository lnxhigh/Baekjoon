#include <bits/stdc++.h>
using namespace std;
const int MAX = 1 << 10;

int N, K;
double P[MAX];
double D[MAX];

int main() {
    // Input
    cin >> N >> K;
    for (int i = 1; i <= K; i++) {
        cin >> P[i]; P[i] /= N;
    }

    // Poisson-Binomial
    D[0] = 1;
    for (int i = 1; i <= K; i++) {
        for (int k = i; k; k--) {
            D[k] = P[i] * D[k - 1] + (1 - P[i]) * D[k];
        }
        D[0] *= 1 - P[i];
    }

    // Result
    double X = 0;
    for (int i = 0; i <= K; i++) {
        if (i % 2 == 0) X += D[i];
    }
    X *= N;

    cout << setprecision(16);
    cout << X << '\n';
    return 0;
}
