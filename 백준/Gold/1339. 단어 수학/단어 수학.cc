#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> words;
long long sums[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    for (const string &word : words) {
        int s = word.size();
        long long mul = 1;
        for (int i = s-1; i >= 0; i--) {
            int k = word[i] - 'A';
            sums[k] += mul;
            mul *= 10;
        }
    }

    sort(sums, sums + 26);

    long long res = 0;
    for (int i = 9; i >= 0; i--) {
        res += sums[26-10+i] * i;
    }
    cout << res << '\n';
    return 0;
}
