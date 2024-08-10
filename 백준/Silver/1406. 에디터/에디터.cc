#include <bits/stdc++.h>
using namespace std;

string str;
list<char> text;
int N;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> str >> N;
    for (char c : str) text.push_back(c);
    auto cur = text.end();
    
    while (N--) {
        char op;
        cin >> op;

        if      (op == 'L') { if (cur != text.begin()) cur--; }
        else if (op == 'D') { if (cur != text.end())   cur++; }
        else if (op == 'B') { if (cur != text.begin()) { cur--; cur = text.erase(cur); } }
        else if (op == 'P') { char c; cin >> c; text.insert(cur, c); }
    }

    for (char c : text) cout << c;
    cout << '\n';
    return 0;
}
