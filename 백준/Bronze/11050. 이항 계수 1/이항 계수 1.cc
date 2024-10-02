#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    K = min(K, N - K);
    int X = 1;
    for (int i = 0; i < K; i++) {
        X *= N - i;
        X /= i + 1;
    }
    cout << X << '\n';
    return 0;
}
