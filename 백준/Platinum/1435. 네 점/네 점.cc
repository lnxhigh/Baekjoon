#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using row = vector<int>;

// Cayley–Menger determinant
// https://en.wikipedia.org/wiki/Cayley%E2%80%93Menger_determinant

int det(const vector<row>& mat) {
    int n = mat.size();
    if (n == 1) return mat[0][0];

    int sum = 0;

    for (int k = 0; k < n; k++) {
        vector<row> sub(n - 1, row(n - 1));
        
        for (int i = 1; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (j != k) sub[i - 1][cnt++] = mat[i][j];
            }
        }

        int mul = (k % 2 == 0) ? 1 : -1;
        sum += mul * mat[0][k] * det(sub);
    }

    return sum;
}

int main() {
    FastIO

    vector<row> arr(5, row(5));

    for (int i = 1; i <= 4; i++) {
        arr[0][i] = arr[i][0] = 1;
    }

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            int x; cin >> x;
            arr[i][j] = x * x;
        }
    }

    string ans = (det(arr) >= 0) ? "YES" : "NO";
    cout << ans << '\n';

    return 0;
}
