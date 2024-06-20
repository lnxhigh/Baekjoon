#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 1000001;
const int DIV = 15746;
int D[N_MAX];

int main() {
    cin >> N;
    D[1] = 1;
    D[2] = 2;
    for (int i = 3; i <= N; i++) {
        D[i] = (D[i-1] + D[i-2]) % DIV;
    }

    cout << D[N] << '\n';
    return 0;
}
