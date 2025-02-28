#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N; cin >> N;
    
    // OEIS A001399
    long long X = ((N + 3) * (N + 3) + 4) / 12;
    cout << X << '\n';
    return 0;
}
