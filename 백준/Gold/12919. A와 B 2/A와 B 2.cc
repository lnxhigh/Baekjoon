#include <bits/stdc++.h>
using namespace std;

string S, T;
queue<string> q;
unordered_set<string> AB;

bool solve(string S, string T) {
    q.push(T);
    
    while (!q.empty()) {
        string X = q.front();
        q.pop();

        if (X.size() == S.size()) {
            if (X == S) return true;
        }

        if (X.back() == 'A') {
            string Y = X;
            Y.pop_back();
            q.push(Y);
        }

        if (X.front() == 'B') {
            string Y = X;
            reverse(Y.begin(), Y.end());
            Y.pop_back();
            q.push(Y);
        }
    }

    return false;
}

int main() {
    cin >> S >> T;
    cout << solve(S, T) << '\n';
    return 0;
}
