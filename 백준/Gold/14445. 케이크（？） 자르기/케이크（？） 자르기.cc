#include <bits/stdc++.h>
using namespace std;

long long solve(long long N) {
    if (N == 1) return 0;
    return (N + 1) / 2;
}

int main() {
    long long N;
    cin >> N;
    cout << solve(N) << '\n';
    return 0;
}
