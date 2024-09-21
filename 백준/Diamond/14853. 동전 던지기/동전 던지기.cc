#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int T;
const int MAX = 1 << 11;
double Beta[MAX][MAX];

int main() {
    FastIO
    cin >> T;
    cout << fixed << setprecision(10);

    // Cache Beta Function
    for (int i = 1; i < MAX; i++) {
        for (int j = 1; j < MAX; j++) {
            Beta[i][j] = beta(i, j);
        }
    }

    while (T--) {
        int n1, m1, n2, m2;
        cin >> n1 >> m1 >> n2 >> m2;
        int a = m1 + 1, b = n1 - m1 + 1, c = m2 + 1, d = n2 - m2 + 1;

        // Incomplete Beta Function
        double x = 1.0 - Beta[c][b+d] / Beta[c][d];
        for (int i = 1; i < a; i++) {
            x -= Beta[c+i][b+d] / (i * Beta[i][b] * Beta[c][d]);
        }
        
        cout << x << '\n';
    }

    return 0;
}
