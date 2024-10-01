#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using Matrix = vector<vector<int64>>;

Matrix multiply(const Matrix &A, const Matrix &B) {
    int N = (int) A.size();
    Matrix X(N, vector<int64>(N));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            for (int k = 0; k < N; k++) {
                X[r][c] += A[r][k] * B[k][c];
            }
        }
    }

    return X;
}

int main() {
    int V, E; cin >> V >> E;
    Matrix graph(V, vector<int64>(V));

    for (int i = 0; i < E; i++) {
        int u, v; cin >> u >> v;
        int64 w; cin >> w;
        graph[u][v] = w;
    }

    Matrix X(V, vector<int64>(V));
    for (int i = 0; i < V; i++) X[i][i] = 1;

    // Transition
    
    for (int i = 0; i < 9; i++) {
        X = multiply(X, graph);
    }

    // Get Max Probability

    int64 res = 0;
    vector<int> cities;

    for (int i = 0; i < V; i++) {
        res = max(res, X[0][i]);
    }

    for (int i = 0; i < V; i++) {
        if (X[0][i] == res) {
            cities.push_back(i);
        }
    }
    
    // Print

    for (int city : cities) cout << city << ' ';
    cout << '\n';

    string ans = to_string(res);
    int len = (int) ans.size();
    ans = string(18 + 1 - len, '0') + ans;

    string integer = string(1, ans.front());
    string decimal = ans.substr(1);
    cout << integer << '.' << decimal << '\n';
    return 0;
}
