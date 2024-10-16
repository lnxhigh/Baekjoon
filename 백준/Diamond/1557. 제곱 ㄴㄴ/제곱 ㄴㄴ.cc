#include <bits/stdc++.h>
using namespace std;
const int MAX = 45000;

bool P[MAX];
int Mu[MAX];

void sieve() {
    fill(P + 2, P + MAX, true);
    fill(Mu, Mu + MAX, 1);

    for (int i = 0; i < MAX; i++) {
        if (!P[i]) continue;
        Mu[i] *= -1;
        for (int j = i + i; j < MAX; j += i) {
            P[j] = false;
            Mu[j] *= -1;
        }
        for (int j = i * i; j < MAX; j += i * i) {
            Mu[j] = 0;
        }
    }
}

int sf(int n) {
    int res = 0;
    for (int i = 1; i * i <= n; i++) {
        res += Mu[i] * (n / (i * i));
    }
    return res;
}

int search(int k) {
    int cur = 0;
    for (int i = 30; i >= 0; i--) {
        int next = cur + (1 << i);
        if (sf(next) < k) cur = next;
    }
    return ++cur;
}

int main() {
    int K; cin >> K;
    sieve();
    int X = search(K);
    cout << X << '\n';
    return 0;
}
