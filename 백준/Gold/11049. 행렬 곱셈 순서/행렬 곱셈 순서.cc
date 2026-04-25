#include <iostream>
#include <vector>
using namespace std;

int N;
int d[501] = {0,};
int DP[501][501] = {0,};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) { cin >> d[i] >> d[i+1]; }

    int i = 1, j = 2;
    while (i != 1 or j != N+1) {
        vector<int> value;
        value.reserve(j-i);
        for (int k = i; k < j; k++) { value.push_back(DP[i][k] + DP[k+1][j] + d[i-1]*d[k]*d[j]); }
        DP[i][j] = value.front();
        for (int x : value) { if (DP[i][j] > x) { DP[i][j] = x; } }
        i++; j++;
        if (j > N) { j = N-i+3; i = 1; }
    }

    cout << DP[1][N] << '\n';
}
