#include <bits/stdc++.h>
using namespace std;

int N, M;
const int N_MAX = 100, M_MAX = 50;
int sixPrice[M_MAX];
int onePrice[M_MAX];

int solve(int oneMin, int sixMin, int N) {
    if (sixMin > oneMin * 6) return oneMin * N;
    return (N/6) * sixMin + min((N%6)*oneMin, sixMin);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> sixPrice[i] >> onePrice[i];
    }
    
    int oneMin = *min_element(onePrice, onePrice + M);
    int sixMin = *min_element(sixPrice, sixPrice + M);
    
    int res = solve(oneMin, sixMin, N);
    cout << res << '\n';
    return 0;
}
