#include <bits/stdc++.h>
using namespace std;

string S;
const int MAX = 26;
int cnt[MAX];

int main() {
    cin >> S;
    for (char c : S) cnt[(int)(c-'a')]++;
    for (char c = 'a'; c <= 'z'; c++) cout << cnt[(int)(c-'a')] << ' ';
    cout << '\n';
    return 0;
}
