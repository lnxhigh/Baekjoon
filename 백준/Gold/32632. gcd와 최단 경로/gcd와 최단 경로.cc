#include <bits/stdc++.h>
using namespace std;

// N 이하의 x 와 서로소인 수들의 개수
int phi(int x, int N) {
    vector<int> p;
    for (int i = 2; i * i <= x; i++) {
        if (x % i != 0) continue;
        p.push_back(i);
        while (x % i == 0) x /= i;
    }
    if (x != 1) p.push_back(x);

    int ret = 0;
    int L = (int) p.size();

    for (int i = 1; i < (1 << L); i++) {
        int cnt = 0;
        int mul = 1;
        for (int k = 0; k < L; k++) {
            if (i >> k & 1) {
                mul *= p[k];
                cnt++;
            }
        }

        int sign = (cnt % 2 == 1) ? +1 : -1;
        ret += (N / mul) * sign;
    }

    ret = N - ret;
    return ret;
}

int solve(int K, int N) {
    if (K <= 2) return N - 1;

    int ret = 0;
    for (int i = 1; i <= N; i++) {
        if (gcd(i, K) <= 2) ret++;
    }
    return ret;
}

int main() {
    int K, N; cin >> K >> N;
    cout << solve(K, N) << '\n';
    return 0;
}
