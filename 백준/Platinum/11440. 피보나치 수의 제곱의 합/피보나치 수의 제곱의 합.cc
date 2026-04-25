#include <iostream>
#include <map>
#define ll long long
#define K 1000000007LL

using namespace std;

ll N;
map<ll,ll> memory;

ll fibonacci(ll N) {
    if (memory.count(N)) return memory[N];

    ll odd = fibonacci((N + 1) / 2LL - 1LL);
    ll even = fibonacci((N + 1) / 2LL);
    if (N % 2LL == 0) memory[N] = ( ( odd + odd + even ) * even ) % K;
    else memory[N] = ( (even * even) % K + (odd * odd) % K ) % K;
    
    return memory[N];
}

int main() {
    cin >> N;
    memory[0LL] = 0LL; memory[1LL] = 1LL;
    cout << ( fibonacci(N) * fibonacci(N+1) ) % K << '\n';
    return 0;
}