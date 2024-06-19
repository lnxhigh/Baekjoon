#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 100;
long long D[N_MAX][2];

int main() {
    cin >> N;
    D[1][0] = 0, D[1][1] = 1;
    for (int i = 1; i < N; i++) {
        D[i+1][0] = D[i][0] + D[i][1];
        D[i+1][1] = D[i][0];
    }
    cout << D[N][0] + D[N][1] << '\n';
    return 0;
}
