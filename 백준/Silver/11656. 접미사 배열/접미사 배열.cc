#include <bits/stdc++.h>
using namespace std;

string S;
vector<string> prefixes;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> S;
    int L = S.size();
    prefixes.reserve(L);

    for (int i = 0; i < L; i++) {
        string prefix = S.substr(i);
        prefixes.push_back(prefix);
    }

    sort(prefixes.begin(), prefixes.end());
    for (const string &prefix : prefixes) {
        cout << prefix << '\n';
    }
    return 0;
}
