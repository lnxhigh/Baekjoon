#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    while (T--) {
        string S;
        cin >> S;
        cout << *S.begin() << *S.rbegin() << '\n';
    }
    
    return 0;
}
