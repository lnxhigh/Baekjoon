#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int A, B, K;
const int MAX = 1 << 22;
int D[MAX], V[MAX];

int digitsum(int x) {
    int sum = 0;

    while (x) {
        int d = x % 10;
        int mul = 1;
        for (int i = 0; i < K; i++) mul *= d;
        sum += mul;
        x /= 10;
    }

    return sum;
}

int dfs(int x) {
    if (D[x]) return D[x];
    else if (!V[x]++) return D[x] = min(x, dfs(digitsum(x)));
    
    int init = x;
    int m = init; // Minimum value in cycle
    
    int cur = digitsum(init);
    while (cur != init) { m = min(m, cur); cur = digitsum(cur); }
    return D[x] = m;
}

int main() {
    cin >> A >> B >> K;
    int64 sum = 0;
    for (int i = A; i <= B; i++) {
        int m = dfs(i);
        sum += (int64) m;
    }
    
    cout << sum << '\n';
    return 0;
}
