#include <bits/stdc++.h>
using namespace std;

string target;
string pattern;

int main() {
    getline(cin, target);
    getline(cin, pattern);

    int res = 0, pos = 0;
    while (true) {
        pos = target.find(pattern, pos);
        if (pos == string::npos) break;

        res++;
        pos += (int) pattern.size();
    }

    cout << res << '\n';
    return 0;
}
