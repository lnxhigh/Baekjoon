#include <bits/stdc++.h>
using namespace std;

string str;
regex pattern("(100+1+|01)+");

int main() {
    cin >> str;
    bool flag = regex_match(str, pattern);
    string ans = flag ? "SUBMARINE" : "NOISE";
    cout << ans << '\n';
    return 0;
}
