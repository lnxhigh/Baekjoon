#include <bits/stdc++.h>
using namespace std;

int TC;
string line;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> TC;
    cin.ignore();

    while (TC--) {
        getline(cin, line);

        stringstream ss(line);

        string word;
        while (ss >> word) {
            reverse(word.begin(), word.end());
            cout << word << ' ';
        }
        cout << '\n';
    }
    return 0;
}
