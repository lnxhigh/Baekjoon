#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define N_MAX 30001
#define M_MAX 100001
#define K_MAX 3001
using namespace std;

int N, M, K;
int parent[N_MAX];
int candy[N_MAX];
int W[N_MAX] = {0,}; 
int V[N_MAX] = {0,};
int weight[N_MAX];
int value[N_MAX];
int DP[N_MAX][K_MAX] = {0,};

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (x > y) parent[x] = y;
    else parent[y] = x;
}

int knapsack(int W[N_MAX], int V[N_MAX], int N, int K) {
    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= K; k++) {
            if (W[i] > k) { DP[i][k] = DP[i-1][k]; }
            else { DP[i][k] = max(V[i] + DP[i-1][k-W[i]], DP[i-1][k]); }
        }
    }

    return DP[N][K];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M >> K;

    // Union-Find
    for (int i = 1; i <= N; i++) {
        cin >> candy[i];
        parent[i] = i;
    }
    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    // Knapsack problem
    for (int i = 1; i <= N; i++) {
        int k = find(i);
        W[k] += 1; // weight
        V[k] += candy[i]; // value
    }

    int S = 0;
    for (int i = 1; i <= N; i++) {
        if (W[i] == 0 and V[i] == 0) continue;
        S++;
        weight[S] = W[i];
        value[S] = V[i];
    }

    cout << knapsack(weight, value, S, K-1) << '\n';
    
    return 0;
}