#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 10;
const int INF = 1 << 20;
int P[MAX], S[MAX];
bool graph[MAX][MAX];

int split(int choice) {
    vector<int> A, B;
    for (int i = 0; i < N; i++) {
        vector<int> &V = (choice & (1 << i)) ? A : B;
        V.push_back(i);
    }

    // Invalid if there is only one group
    if (A.empty() || B.empty()) return INF;

    // Rebuild new graph
    vector<vector<int>> groups = { A, B };
    bool isConnected[MAX][MAX];
    fill(&isConnected[0][0], &isConnected[N-1][N-1] + 1, false);

    for (vector<int> &group : groups) {
        for (int i : group) {
            for (int j : group) {
                isConnected[i][j] = graph[i][j];
            }
        }
    }

    // Floyd
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (isConnected[i][k] && isConnected[k][j]) isConnected[i][j] = true;
            }
        }
    }

    // Check interconnection
    for (vector<int> &group : groups) {
        for (int i : group) {
            for (int j : group) {
                if (!isConnected[i][j]) {
                    return INF;
                }
            }
        }
    }

    // Calculate population difference
    int a = 0, b = 0;
    for (int k : A) a += P[k];
    for (int k : B) b += P[k];

    int diff = abs(a - b);
    return diff;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    for (int i = 0; i < N; i++) {
        int size;
        cin >> size;
        S[i] = size;
        
        while (size--) {
            int district;
            cin >> district;
            --district;
            
            graph[i][district] = true;
            graph[district][i] = true;

        }
        
        graph[i][i] = true;
    }

    int res = INF;
    for (int choice = 0; choice < (1 << N); choice++) {
        int tmp = split(choice);
        res = min(res, tmp);
    }

    if (res >= INF) res = -1;
    cout << res << '\n';
    return 0;
}
