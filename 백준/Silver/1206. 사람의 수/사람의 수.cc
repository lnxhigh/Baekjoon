#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 50;
int A[N_MAX];

bool check(int K) {
    for (int i = 0; i < N; i++) {
        int X = A[i];
        int S = X * K, E = (X + 1) * K;
        S = (S % 1000 == 0) ? S / 1000 : S / 1000 + 1;
        E = (E % 1000 == 0) ? E / 1000 - 1 : E / 1000;
        
        if (S > E) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        double X;
        cin >> X;
        A[i] = round(X * 1000.0);
    }

    int ans = 1000;
    for (int k = 1; k < 1000; k++) {
        if (check(k)) {
            ans = k;
            break;
        }
    }

    cout << ans << '\n';
    return 0;
}
