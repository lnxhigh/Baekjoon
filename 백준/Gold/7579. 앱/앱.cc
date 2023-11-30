#include <iostream>
#include <vector>
#define N_MAX 100
#define COST_MAX 10000
#define INF 2147483647
using namespace std;

int N, M;
int m, c;

int value_[N_MAX+1];
int weight_[N_MAX+1];
vector<int> value;
vector<int> weight;
int knapsack[N_MAX+1][COST_MAX+1];

int cost_max = 0;
int cost_min = INF;
int cost_free = 0;

int Max(int x, int y) { return x > y ? x : y ; }
int Min(int x, int y) { return x < y ? x : y ; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> m;
        value_[i] = m;
    }
    for (int i = 1; i <= N; i++) {
        cin >> c;
        weight_[i] = c;
    }

    value.push_back(0);
    weight.push_back(0);

    for (int i = 1; i <= N; i++) {
        if (weight_[i] != 0) {
            value.push_back(value_[i]);
            weight.push_back(weight_[i]);
        }
        else {
            cost_free += value_[i];
        }
    }
    
    for (int k : weight) cost_max += k;
    N = value.size() - 1;

    for (int i = 0; i <= N; i++) knapsack[i][0] = 0;
    for (int w = 0; w <= cost_max; w++) knapsack[0][w] = 0;

    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= cost_max; w++) {
            if (weight[i] > w) knapsack[i][w] = knapsack[i-1][w];
            else knapsack[i][w] = Max(knapsack[i-1][w], value[i] + knapsack[i-1][w-weight[i]]);
        }
    }

    for (int w = 0; w <= cost_max; w++) {
        if (knapsack[N][w] + cost_free >= M) cost_min = Min(cost_min, w);
    }

    cout << cost_min << '\n';
    return 0;
}