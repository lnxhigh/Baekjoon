#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N;
const int MAX = 1 << 7;
string words[MAX];

string recode(const string &words) {
    int alpha[26];
    memset(alpha, -1, sizeof(alpha));

    int idx = 0;
    for (char c : words) {
        int i = (int)(c-'a');
        if (alpha[i] != -1) continue;
        alpha[i] = idx++;
    }

    string res;
    for (char c : words) {
        char x = 'a' + alpha[(int)(c-'a')];
        res.push_back(x);
    }
    return res;
}

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    unordered_map<string,int> wordMap;
    for (int i = 0; i < N; i++) {
        wordMap[recode(words[i])]++;
    }

    int res = 0;
    for (auto p : wordMap) {
        int n = p.second;
        res += n * (n-1) / 2;
    }

    cout << res << '\n';
    return 0;
}
