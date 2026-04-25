#include <iostream>
using namespace std;

int tri[501][501];
int dp[501][501];
int N;
int Max(int x, int y) { return x > y ? x : y ; } 

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int h = 1; h <= N; h++) {
        for (int i = 1; i <= h; i++) {
            cin >> tri[h][i];
        }
    }

    for (int i = 1; i <= N; i++) {
        dp[1][i] = tri[N][i];
    }
    
    for (int h = 2; h <= N; h++) {
        for (int i = 1; i <= N+1-h; i++) {
            dp[h][i] = Max(dp[h-1][i+1], dp[h-1][i]) + tri[N+1-h][i];
        }
    }

    cout << dp[N][1] << '\n';
    return 0;
}