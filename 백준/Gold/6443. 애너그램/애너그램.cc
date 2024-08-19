#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;

    while (N--) {
        string word;
        cin >> word;
        sort(word.begin(), word.end());
        do { cout << word << '\n'; } while (next_permutation(word.begin(), word.end()));
    }

    return 0;
}
