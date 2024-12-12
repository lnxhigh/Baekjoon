#include <bits/stdc++.h>
using namespace std;

int main() {
    int G; cin >> G;
    
    int sq = sqrt(G);
    if (sq * sq < G) sq++;
    bool exist = false;

    for (int i = sq; i <= G; i++) {
        if (G % i != 0) continue;
        int x = i, y = G / i;
        if ((x + y) % 2 != 0 || (x - y) % 2 != 0) continue;

        int cur = (x + y) / 2, prv = (x - y) / 2;
        if (cur == 0 || prv == 0) continue;

        exist = true;
        cout << cur << '\n';
    }

    if (!exist) cout << -1 << '\n';

    return 0;
}
