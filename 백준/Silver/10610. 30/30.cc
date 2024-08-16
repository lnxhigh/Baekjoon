#include <bits/stdc++.h>
using namespace std;

string S;

int main() {
    cin >> S;
    sort(S.begin(), S.end(), [] (char &x, char &y) { return x > y; });

    int sum = 0;
    for (char c : S) sum += (c - '0');
    if (sum % 3 != 0 || S[S.size()-1] != '0') cout << -1 << '\n';
    else cout << S << '\n';
    
    return 0;
}
