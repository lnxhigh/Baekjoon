#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 20;

int N;
int A[MAX];

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) { cin >> A[i]; }
    sort(A, A + N);

    int g = A[0];
    for (int i = 0; i < N; i++) { g = gcd(g, A[i]); }
    for (int i = 0; i < N; i++) { A[i] /= g; }

    vector<pair<int,int>> all;

    // Case 1: Remove A[0]
    int first = A[1];
    for (int i = 1; i < N; i++) {
        first = gcd(first, A[i]);
    }
    if (first > 1) { all.push_back({ first, 0 }); }

    // Case 2: Do not remove A[0]
    if (A[0] != 1) {
        int cnt = 0;
        int pass = 0;
        int second = A[0];

        for (int i = 0; i < N; i++) {
            int nxt = gcd(second, A[i]);
            if (nxt > 1) { second = nxt; }
            else { cnt++; pass =  i; }
        }

        if (cnt <= 1 && second > 1) {
            all.push_back({ second, pass });
        }
    }

    // Result
    if (all.empty()) {
        cout << -1 << '\n';
    }
    else {
        sort(all.begin(), all.end());
        auto [ans, idx] = *all.rbegin();
        cout << ans * g << ' ' << A[idx] * g << '\n';
    }

    return 0;
}
