#include <bits/stdc++.h>
using namespace std;

int N, K;
const int L = 21;
vector<int> words;
vector<int> V;

string antatica = "antatica";
int P[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력 처리
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        int bits = 0;
        for (char letter : word) {
            int k = letter - 'a';
            bits = bits | (1 << k);
        }
        words.push_back(bits);
    }
    
    // 알파벳 압축 복원
    int cur = 0;
    for (int i = 0; i < 26; i++) {
        if (antatica.find('a' + i) == string::npos) P[cur++] = i;
    }

    // L개 중 K개 선택
    for (int bits = 0; bits < (1 << L); bits++) {
        int cnt = 0;
        for (int k = 0; k < L; k++) { if (bits & (1 << k)) cnt++; }
        if (cnt != K - 5) continue;
        
        int newBits = 0;
        for (char c : { 'a', 'n', 't', 'i', 'c' }) {
            newBits = newBits | (1 << (c - 'a'));
        }
        for (int k = 0; k < L; k++) { 
            if (bits & (1 << k)) newBits = newBits | (1 << P[k]); 
        }
        V.push_back(newBits);
    }

    // 결과 출력
    int res = 0;
    for (const int &bits : V) {
        int cnt = 0;
        for (const int &word : words) {
            if ((bits & word) == word) cnt++;
        }
        res = max(res, cnt);
    }
    
    cout << res << '\n';
    return 0;
}
