#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 1 << 6;
pair<int,int> A[MAX];

int solve(int k) {
    int res = 0;
    const auto& [x, y] = A[k];

    for (int i = 0; i < N; i++) {
        const auto& [x_, y_] = A[i];
        if (x_ > x && y_ > y) res++;
    }

    return ++res;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        A[i] = { x, y };
    }
    for (int i = 0; i < N; i++) {
        cout << solve(i) << ' ';
    }
    cout << '\n';

    return 0;
}
