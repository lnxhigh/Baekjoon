#include <iostream>
#include <vector>
#define ll long long
#define MOD 1000000007LL
using namespace std;

int D;
int answer = 0;

vector<vector<ll>> graph = {
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 0, 1},
    {0, 0, 0, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0, 1, 0}
};

vector<vector<ll>> operator* (const vector<vector<ll>> &left, const vector<vector<ll>> &right) {
    const int R = left.size();
    const int C = right[0].size();;
    vector<vector<ll>> res(R, vector<ll>(C));

    const int K1 = left[0].size();
    const int K2 = right.size();
    if (K1 != K2) cerr << "Dimension Error" << '\n';

    for (int r = 0; r < R; r++) {
        vector<ll> row(C);
        for (int c = 0; c < C; c++) {
            int value = 0;
            for (int k = 0; k < K1; k++) {
                value = ( value + left[r][k]*right[k][c] ) % MOD;
            }
            row[c] = value;
        }
        res[r] = row;
    }

    return res;
}

vector<vector<ll>> operator^ (const vector<vector<ll>> &mat, const int p) {
    const int R = mat.size();
    const int C = mat[0].size();
    if (R != C) { 
        cerr << "Dimension Error" << '\n';
    }

    if (p == 0) {
        vector<vector<ll>> res(R, vector<ll>(C, 0));
        for (int r = 0; r < R; r++) {
            res[r][r] = 1;
        }
        return res;
    }
    else if (p == 1) {
        return mat;
    }
    
    if (p % 2 == 0) {
        vector<vector<ll>> res = mat ^ (p/2);
        return res * res;
    }
    else if (p % 2 == 1) {
        vector<vector<ll>> res = mat ^ (p/2);
        return res * res * mat;
    }
}

void print(const vector<vector<ll>> &mat) {
    const int R = mat.size();
    const int C = mat[0].size();
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cout << mat[r][c] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> D;
    answer = (graph ^ D)[0][0];
    cout << answer << '\n';

    return 0;
}
