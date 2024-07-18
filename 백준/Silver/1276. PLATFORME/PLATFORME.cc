#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 101;
vector<int> A[N_MAX];
int H[N_MAX * N_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int Y, X1, X2;
        cin >> Y >> X1 >> X2;
        vector<int> V;
        for (int k : { Y, X1, X2 - 1}) V.push_back(k);
        A[i] = V;
    }

    sort(A, A + N, [] (const vector<int> &left, const vector<int> &right) {
        return left[0] < right[0];
    });

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int Y = A[i][0], X1 = A[i][1], X2 = A[i][2];
        ans += Y - H[X1];
        ans += Y - H[X2];
        for (int k = X1; k <= X2; k++) H[k] = Y;
    }
    
    cout << ans << '\n';
    return 0;
}
