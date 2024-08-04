#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 1 << 17;

bool isPerfect(int N) {
    if (N == 6 || N == 28 || N == 496 || N == 8128) return true;
    return false;
}

void handlePerfect(int N) {
    cout << N << ' ' << '=' << ' ';
    cout << 1 << ' ';
    for (int i = 2; i < N; i++) {
        if (N % i == 0) cout << '+' << ' ' << i << ' ';
    }
    cout << '\n';
}

void handleNotPerfect(int N) {
    cout << N << " is NOT perfect." << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true) {
        int N;
        cin >> N;
        if (N == -1) break;

        if (isPerfect(N)) handlePerfect(N);
        else handleNotPerfect(N);
    }

    return 0;
}
