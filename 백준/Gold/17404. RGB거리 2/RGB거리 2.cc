#include <iostream>
using namespace std;
int N;
int cost[1000][3] = {0,};
int MAX = 1000*1000;
int ans = MAX;
int Min(int a, int b) { return a < b ? a : b; }
enum { R, G, B, K };

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) { 
        cin >> cost[i][R] >> cost[i][G] >> cost[i][B]; 
    }

    for (int s = 0; s < K; s++) {
        int house[1000][K];

        // 1. Fix the color of the first house
        house[0][s] = cost[0][s];
        house[0][(s+1)%K] = MAX; house[0][(s+2)%K] = MAX;

        // 2. Fill the DP table
        for (int i = 1; i < N; i++) {
            for (int k = 0; k < K; k++) {
                house[i][k] = Min(house[i-1][(k+1)%K], house[i-1][(k+2)%K]) + cost[i][k];
            }
        }

        // 3. Remove the case where the color of the first and the Nth house are the same
        int value = Min(house[N-1][(s+1)%K], house[N-1][(s+2)%K]);
        ans = Min(ans, value);
    }

    cout << ans << '\n';
    
    return 0;
}