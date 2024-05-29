#include <bits/stdc++.h>
using namespace std;

int T, N;
vector<int> bits;
vector<vector<int>> constraints;
int answer = 0;

bool check(int bit, vector<int> &constraint) {
    for (int i : constraint) {
        // Not acceptable if all are one
        if (!(bit & (1 << i))) return true;
    }
    return false;
}

bool checkAll(int bit, vector<vector<int>> &constraints) {
    bool res = true;
    for (vector<int> &constraint : constraints) {
        // Not Acceptable if at least one is not acceptable
        if (!check(bit, constraint)) return false;
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T >> N;
    for (int bit = 0; bit < (1 << T); bit++) {
        bits.push_back(bit);
    }

    for (int i = 0; i < N; i++) {
        int Z;
        cin >> Z;
        vector<int> constraint;

        for (int z = 0; z < Z; z++) {
            int ingredient;
            cin >> ingredient;
            constraint.push_back(ingredient - 1);
        }

        constraints.push_back(constraint);
    }

    for (int bit : bits) {
        if (checkAll(bit, constraints)) answer++;
    }

    cout << answer << '\n';

    return 0;
}
