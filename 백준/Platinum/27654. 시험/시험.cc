#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100'000;

int N, K;
pair<double,double> Data[MAX];
double Diff[MAX];

int main() {
    FastIO

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        double p, q; cin >> p >> q;
        Data[i] = { p, q };
    }

    double lo = 0.0, hi = 1.0;
    double err = 1e-10;

    while (hi - lo > err) {
        double mid = (lo + hi) / 2;
        
        for (int i = 0; i < N; i++) {
            auto& [p, q] = Data[i];
            Diff[i] = p - mid * q;
        }
        sort(Diff, Diff + N);

        double sum = 0;
        for (int i = N - 1; i > N - K - 1; i--) {
            sum += Diff[i];
        }

        if (sum >= 0) lo = mid;
        else hi = mid;
    }

    double ans = (lo + hi) / 2;
    cout << setprecision(16);
    cout << ans << '\n';

    return 0;
}
