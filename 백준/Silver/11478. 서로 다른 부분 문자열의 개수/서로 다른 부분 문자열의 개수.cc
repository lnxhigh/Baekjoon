#include <bits/stdc++.h>
using namespace std;

string S;
unordered_set<string> strings;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> S;

    int size = S.size();
    for (int len = 1; len <= size; len++) {
        for (int i = 0; i < size - len + 1; i++) {
            strings.insert(S.substr(i, len));
        }
    }

    int answer = strings.size();
    cout << answer << '\n';
    
    return 0;
}
