#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ll N, K; cin >> N >> K;
    K = min(K, N - K);
    
    ll g = gcd(N, K);
    N /= g, K /= g;
    cout << N * (K - 1) << '\n';
}
