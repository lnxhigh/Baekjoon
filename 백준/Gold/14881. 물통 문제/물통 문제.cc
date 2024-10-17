#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

// 작은 물통을 채운 후 큰 물통으로 계속 붓는 시행을 생각하자
// ax + by = c 가 되는 (x, y) 가 존재하면 c 리터를 구성할 수 있다

bool solve(int a, int b, int c) {
    if (c > max(a, b)) return false;
    int g = gcd(a, b);
    return c % g == 0;
}

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int a, b, c; 
        cin >> a >> b >> c;
        string ans = solve(a, b, c) ? "YES" : "NO";
        cout << ans << '\n';
    }
    return 0;
}
