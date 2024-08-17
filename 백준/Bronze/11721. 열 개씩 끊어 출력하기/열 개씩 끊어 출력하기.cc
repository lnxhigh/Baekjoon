#include <bits/stdc++.h>
using namespace std;

int N;
string word;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> word;
    N = word.size();

    for (int i = 0; i < N; i += 10) {
        cout << word.substr(i, 10) << '\n';
    }
    return 0;
}
