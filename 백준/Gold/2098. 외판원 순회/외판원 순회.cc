#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N = 1, M = 1;
int visited = 0;
int W[16][16] = {0,};
int dp[16][65536] = {0,};

int DP(int i, int visited) {
    if (visited == M-1) { return 0; }
    if (dp[i][visited] != 0) { return dp[i][visited]; }

    dp[i][visited] = 1000000 * N; 
    int value = 0;

    for (int j = 0; j < N; j++) {
        if (((visited & (1 << j)) >> j) == 0) {
            value = W[i][j] + DP(j, visited | (1 << j));
            if (dp[i][visited] > value) { dp[i][visited] = value; }
        }
    }
    
    return dp[i][visited];
}

int last(int i, int visited) {
    if (visited == M-1) { return i; }

    int x = 1000000 * N;
    int value, minIdx = -1;

    for (int j = 0; j < N; j++) {
        if (((visited & (1 << j)) >> j) == 0) {
            value = W[i][j] + DP(j, visited | (1 << j));
            if (x > value) { x = value; minIdx = j; }
        }
    }

    return last(minIdx, visited | (1 << minIdx));
}

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        M *= 2;
        for (int j = 0; j < N; j++) {
            cin >> W[i][j];
            if ((i != j) and (W[i][j] == 0)) { W[i][j] = 1000000 * N; }
        }
    }

    vector<int> value;

    for (int i = 0; i < N; i++) { DP(i, 1 << i); }
    for (int i = 0; i < N; i++) { value.push_back( dp[i][1 << i] + W[last(i, 1 << i)][i] ); }
    int answer = *min_element(value.begin(), value.end());

    cout << answer << '\n';
}
