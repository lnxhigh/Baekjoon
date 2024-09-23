#include <bits/stdc++.h>
using namespace std;

bool IsPrime(int X) {
    if (X <= 1) return false;
    for (int i = 2; i * i <= X; i++) {
        if (X % i == 0) return false;
    }
    return true;
}

int main() {
    int N; cin >> N;
    vector<int> p;
    for (int i = 0; i < 128; i++) {
        if (IsPrime(i)) p.push_back(i);
    }
    
    vector<int> V;
    for (int i = 0; i < (int) p.size() - 1; i++) {
        V.push_back(p[i] * p[i+1]);
    }

    auto iter = upper_bound(V.begin(), V.end(), N);
    cout << *iter << '\n';
    return 0;
}
