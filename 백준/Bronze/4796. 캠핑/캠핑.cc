#include <bits/stdc++.h>
using namespace std;

int T, L, P, V;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (++T) {
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0) break;
        int X = V / P * L + min(V % P, L);
        cout << "Case " << T << ": " << X << '\n';
    }

    return 0;
}
