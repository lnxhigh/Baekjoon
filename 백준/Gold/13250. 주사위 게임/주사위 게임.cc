#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000005;

int N;
double D[MAX];

double dfs(int n) {
    if (n <= 0) return 0;
    if (D[n]) return D[n];

    double x = 0;
    for (int i = 1; i <= 6; i++) {
        x += dfs(n - i) + 1;
    }
    return D[n] = x / 6;
}

int main() {
    cin >> N;
    cout << setprecision(16);
    cout << dfs(N) << '\n';
    return 0;
}
