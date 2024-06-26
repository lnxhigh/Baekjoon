#include <bits/stdc++.h>
using namespace std;

int N, K;
const int L = 21;
vector<string> words;
vector<int> V;
int P[26];

bool check(const int &bits, const string &word) {
    for (char letter : word) {
        int k = letter - 'a';
        if (bits & (1 << P[k])) continue;
        return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력 처리
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }
    
    // 알파벳 압축
    int cur = 0;
    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        if (c == 'a' || c == 'n' || c == 't' || c == 'i' || c == 'c') P[i] = L;
        else P[i] = cur++;
    }

    // L개 중 K개 선택
    for (int bits = 0; bits < (1 << L); bits++) {
        int cnt = 0;
        for (int k = 0; k < L; k++) { if (bits & (1 << k)) cnt++; }
        if (cnt == K - 5) V.push_back(bits | (1 << L));
    }

    // 문자열 압축
    for (string &word : words) {
        unordered_set<char> s;
        for (char letter : word) s.insert(letter);
        string newWord = "";
        for (char letter : s) newWord += letter;
        word = newWord;
    }

    int res = 0;
    for (int &bits : V) {
        int cnt = 0;
        for (const string &word : words) {
            if (check(bits, word)) cnt++;
        }
        res = max(res, cnt);
    }
    
    cout << res << '\n';
    return 0;
}
