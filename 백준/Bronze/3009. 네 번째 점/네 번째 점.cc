#include <bits/stdc++.h>
using namespace std;

int a, b;
unordered_map<int,int> X, Y;

int main() {
    for (int i = 0; i < 3; i++) {
        cin >> a >> b;
        X[a]++; Y[b]++;
    }

    for (auto p : X) { if (p.second == 1) cout << p.first << ' '; }
    for (auto p : Y) { if (p.second == 1) cout << p.first << ' '; }
    cout << '\n';
    return 0;
}
