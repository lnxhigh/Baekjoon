#include <bits/stdc++.h>
using namespace std;

string A, B;
const int MAX = 1 << 12;
int D[MAX][MAX];

int main() {
    cin >> A >> B;

    int res = 0;
    for (int i = 1; i <= (int) A.size(); i++) {
        for (int j = 1; j <= (int) B.size(); j++) {
            if (A[i-1] == B[j-1]) {
                D[i][j] = D[i-1][j-1] + 1;
                res = max(res, D[i][j]);
            }
        }
    }

    cout << res << '\n';
    return 0;
}
