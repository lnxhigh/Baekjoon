#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int N, M;
char table[10][10];

vector<vector<int>> seq_N[10], seq_M[10];

void generate_sequence(int n, int k, vector<int> &x, vector<vector<int>> &seq) {
    if (k == x.size()) {
        seq.push_back(x);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (x.empty() || (x.size() == 1) || (x[1] - x[0] == i - x.back())) {
            x.push_back(i); 
            generate_sequence(n, k, x, seq);
            x.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> table[i][j];
        }
    }
    
    vector<int> x;
    int max_val = N > M ? N : M;
    for (int k = 1; k <= max_val; k++) {
        generate_sequence(N, k, x, seq_N[k]);
    }
    for (int k = 1; k <= max_val; k++) {
        generate_sequence(M, k, x, seq_M[k]);
    }

    int ans = -1;
    for (int i = max_val; i >= 1; i--) {
        for (vector<int> row : seq_N[i]) {
            for (vector<int> col : seq_M[i]) {
                string num_str = "";
                for (int k = 0; k < i; k++) {
                    num_str += table[row[k]][col[k]];
                }

                int num = stoi(num_str);
                int temp = int(sqrt(num));
                if (num == temp * temp) {
                    if (num > ans) {
                        ans = num;
                    }
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}