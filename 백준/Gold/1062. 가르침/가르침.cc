#include <bits/stdc++.h>
using namespace std;

int N, K;
const int L = 21;
vector<int> words;
vector<int> V;

string antatica = "antatica";
int P[26];

void choose(int N, int K, vector<int> &V) {
    vector<int> C;
    for (int i = 0; i < N - K; i++) C.push_back(0);
    for (int i = 0; i < K; i++) C.push_back(1);
    do {
        int newBits = 0;
        for (char c : { 'a', 'n', 't', 'i', 'c' }) { 
            newBits = newBits | (1 << (c - 'a')); 
        }
        for (int k = 0; k < N; k++) { 
            if (C[k] == 1) newBits = newBits | (1 << P[k]); 
        }
        V.push_back(newBits);
    } while (next_permutation(C.begin(), C.end()));
}

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
    K -= 5;
    if (K >= 0) choose(L, K, V);

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
