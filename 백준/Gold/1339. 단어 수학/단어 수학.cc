#include <bits/stdc++.h>
using namespace std;

// 백트래킹 느리다 ..
// 시간초과 날 것 같음

int N, K;
int alpha[26];
vector<string> words;

long long ans = 0;

long long word2value(const string &word, vector<int> &table) {
    long long res = 0, mul = 1;
    int s = word.size();
    for (int i = s-1; i >= 0; i--) {
        int k = alpha[word[i]-'A'];
        res += mul * table[k];
        mul *= 10;
    }
    return res;
}

void f(int depth, vector<int> &table) {
    if (depth == K) {
        long long res = 0;
        for (const string &word : words) {
            res += word2value(word, table);
        }

        ans = max(ans, res);
        return;
    }

    for (int i = 0; i < 10; i++) {
        bool check = true;
        for (int x : table) if (x == i) check = false;
        if (!check) continue;

        table.push_back(i);
        f(depth+1, table);
        table.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    memset(alpha, -1, sizeof(alpha));
    for (const string &word : words) {
        for (char letter : word) {
            int k = letter - 'A';
            if (alpha[k] == -1) alpha[k] = K++;
        }
    }
    
    vector<int> table;
    f(0, table);
    cout << ans << '\n';

    return 0;
}
