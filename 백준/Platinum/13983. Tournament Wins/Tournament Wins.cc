#include <bits/stdc++.h>
using namespace std;

int K, R;

double lchoose(int n, int k) {
    return lgamma(n + 1) - lgamma(k + 1) - lgamma(n - k + 1);
}

double f(int i) {
    int all = (1 << K) - 1;
    int loser = (1 << K) - R;
    int group = (1 << i) - 1;
    if (loser < group) return 0;

    double x = lchoose(loser, group);
    double y = lchoose(all, group);
    return exp(x - y);
}

int main() {
    cin >> K >> R;

    double ans = 0;
    for (int i = 1; i <= K; i++) {
        double p = f(i) - f(i + 1);
        ans += i * p;
    }

    cout << fixed << setprecision(5);
    cout << ans << '\n';
    return 0;
}
