#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> D(N+1);
    for (int i = 1; i <= N; i++) {
        D[i] = 5;
        for (int k = 1; k * k <= i; k++) {
            D[i] = min(D[i], D[i-k*k] + 1);
        }
    }
    
    cout << D[N] << '\n';
    return 0;
}
