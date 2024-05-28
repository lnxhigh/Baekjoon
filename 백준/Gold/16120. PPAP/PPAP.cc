#include <bits/stdc++.h>
using namespace std;

string S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> S;

    int len = S.size();
    string check = "";
    for (int i = 0; i < len; i++) {
        check += S[i];
        if (check.size() >= 4 && check.substr(check.size()-4, 4) == "PPAP") {
            check.erase(check.size() - 3, check.size());
        }
    }

    string answer = (check == "P") ? "PPAP" : "NP";
    cout << answer << "\n";
    
    return 0;
}
