#include <bits/stdc++.h>
#define N_MAX 10001
using namespace std;

int self[11111] = {0,};

int d(int n) {
    int res = n;
    while (n != 0) {
        res += n % 10;
        n /= 10;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 1; i < N_MAX; i++) {
        self[d(i)]++;
    }

    for (int i = 1; i < N_MAX; i++) {
        if (self[i] > 0) continue;
        cout << i << '\n';
    }

    return 0;
}
