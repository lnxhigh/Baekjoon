#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 1 << 10;
int A[MAX], D[MAX];

int main() {
    cin >> N;
    vector<int> A(N), D(N, 1);
    for (int &x : A) cin >> x;

    for (int i = 1; i < N; i++) {
        for (int k = 0; k < i; k++) {
            if (A[k] >= A[i]) continue;
            if (A[k] < A[i]) D[i] = max(D[i], D[k] + 1);
        }
    }

    int res = *max_element(D.begin(), D.end());
    cout << res << '\n';
    return 0;
}
