#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    int64 A, B, C;
    cin >> A >> B >> C;
    int64 ans = A % 16 * 256 + B % 16 * 16 + C % 16 * 1;
    
    string s = to_string(ans);
    int pad = 4 - s.size();
    if (pad > 0) cout << string(pad, '0');
    cout << s << '\n';
    return 0;
}
