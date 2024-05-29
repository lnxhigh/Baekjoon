#include <bits/stdc++.h>
using namespace std;

int T, N;
vector<int> bits;
vector<int> constraints;
int answer = 0;

bool check(int bit, vector<int> &constraints) {
    for (const int &constraint : constraints) {
        if ((bit & constraint) == constraint) return false;
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

        int constraint = 0;
        for (int z = 0; z < Z; z++) {
            int ingredient;
            cin >> ingredient;
            constraint += 1 << (ingredient - 1);
        }

        constraints.push_back(constraint);
    }

    for (int bit : bits) {
        if (check(bit, constraints)) answer++;
    }
    cout << answer << '\n';

    return 0;
}
