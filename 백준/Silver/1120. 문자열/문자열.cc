#include <bits/stdc++.h>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    int res = 1 << 6;
    for (int i = 0; i <= (int) B.size() - (int) A.size(); i++) {
        int diff = 0;
        for (int k = 0; k < (int) A.size(); k++) {
            if (A[k] != B[i+k]) diff++;
        }
        res = min(res, diff);
    }

    cout << res << '\n';
    return 0;
}
