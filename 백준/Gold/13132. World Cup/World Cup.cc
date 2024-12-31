#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 16;

int N;
double M, B;
double P[MAX], R[MAX];

double f(int x) {
    double money = 1;
    double p = 1;

    for (int i = 0; i < N; i++) {
        // Win
        if (x >> i & 1) {
            p *= P[i];
            money *= 1 + M * (R[i] - 1);
        }
        // Lose
        else {
            p *= 1 - P[i];
            money *= 1 - M;
            if (money <= B) return 0;
        }
    }

    if (money <= 1) return 0;
    return p;
}

int main() {
    FastIO
    cin >> N; 
    cin >> M >> B; M /= 100.0, B /= 100.0;

    for (int i = 0; i < N; i++) {
        cin >> P[i]; P[i] /= 100.0;
        cin >> R[i];
    }

    double ans = 0.0;
    for (int i = 0; i < (1 << N); i++) {
        ans += f(i);
    }
    
    ans *= 100.0;
    cout << setprecision(16);
    cout << ans << '\n';
    return 0;
}
