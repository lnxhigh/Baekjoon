#include <bits/stdc++.h>
using namespace std;
const double eps = 1.0 / 10007.0;

int N, K;
vector<int> factors[5001];

void init() {
    for (int i = 1; i <= N; i++) {
        int x = i;
        for (int k = 2; k * k <= x; k++) {
            if (x % k != 0) continue;
            while (x % k == 0) x /= k;
            factors[i].push_back(k);
        }
        if (x != 1) {
            factors[i].push_back(x);
        }
    }
}

// The number of (A, B) s.t. A / B <= value where gcd(A, B) = 1
int f(double value) {
    int res = 0;

    for (int B = 1; B <= N; B++) {
        int A = (int) (value * B);

        // Inclusion-Exclusion Principle
        int div = 0;
        int size = (int) factors[B].size();
        for (int i = 1; i < (1 << size); i++) {
            int mul = 1, sign = -1;
            for (int k = 0; k < size; k++) {
                if (i >> k & 1) {
                    mul *= factors[B][k];
                    sign = -sign;
                }
            }
            div += sign * (A / mul);
        }
        
        res += A - div;
    }

    return ++res; // Include A = 0
}

int main() {
    cin >> N >> K;
    init();

    double value = 0.0;
    double low = eps, high = 1.0 - eps;

    // Floating Point Error ...
    for (int i = 0; i < 30; i++) {
        double mid = (low + high) / 2.0;
        if (f(mid) < K) low = mid, value = mid;
        else high = mid;
    }

    pair<int,int> ans;
    double error = 1.0;
    for (int B = 1; B <= N; B++) {
        int A = ceil(B * value);
        if (gcd(A, B) != 1) continue;

        double p = (double) A / (double) B;
        double delta = p - value;
        if (delta < error) error = delta, ans = { A, B };
    }
    
    auto [A, B] = ans;
    cout << A << ' ' << B << '\n';
    return 0;
}
