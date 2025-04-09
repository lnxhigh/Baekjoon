#include <bits/stdc++.h>
using namespace std;

int main() {
    int D1, D2; cin >> D1 >> D2;

    set<pair<int,int>> all;
    
    for (int i = D1; i <= D2; i++) {
        for (int j = 0; j < i; j++) {
            int g = gcd(i, j);
            all.insert({ i / g, j / g });
        }
    }

    int ans = all.size();
    cout << ans << '\n';
    
    return 0;
}
