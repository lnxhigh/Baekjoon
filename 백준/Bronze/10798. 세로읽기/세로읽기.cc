#include <bits/stdc++.h>
using namespace std;

const int N = 5, L = 15;
vector<string> S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        S.push_back(s);
    }
    
    for (int i = 0; i < L; i++) {
        for (int k = 0; k < N; k++) {
            const string &word = S[k];
            if (i < word.size()) cout << word[i];
        }
    }
    cout << '\n';

    return 0;
}
