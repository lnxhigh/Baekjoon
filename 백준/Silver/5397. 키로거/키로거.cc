#include <bits/stdc++.h>
using namespace std;

int TC;
string keyLog;

string hack(string keyLog) {
    string password = "";
    stack<char> left;
    stack<char> right;
    
    for (char c : keyLog) {
        if (isalpha(c) || isdigit(c)) {
            left.push(c);
        }
        else if (c == '<') {
            if (left.empty()) continue;
            right.push(left.top());
            left.pop();
        }
        else if (c == '>') {
            if (right.empty()) continue;
            left.push(right.top());
            right.pop();
        }
        else if (c == '-') {
            if (!left.empty()) left.pop();
        }
    }

    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    while (!right.empty()) {
        password += right.top();
        right.pop();
    }

    return password;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> TC;
    while (TC--) {
        cin >> keyLog;
        string password = hack(keyLog);
        cout << password << '\n';
    }

    return 0;
}
