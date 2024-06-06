#include <bits/stdc++.h>
#define SIZE 26
using namespace std;

int N;

class Trie {
    private:
    Trie* next[SIZE];
    bool finish;
    int numNext;
    
    public:
    Trie() : finish(false), numNext(0) {
        fill(next, next + SIZE, nullptr);
    }

    ~Trie() {
        for (int i = 0; i < SIZE; i++) {
            if (next[i]) delete next[i];
        }
    }

    void insert(const string &word) {
        Trie* node = this;
        for (char letter : word) {
            int k = letter - 'a';
            if (!node->next[k]) {
                node->numNext += 1;
                node->next[k] = new Trie();
            }
            node = node->next[k];
        }
        node->finish = true;
    }

    int count(const string &word) {
        Trie* node = this;
        int res = 0;
        int s = word.size();

        // 모듈이 단어의 첫 번째 글자를 추론하지는 않는다
        if (s == 0) return res;
        res++;
        int first = word[0] - 'a';
        if (node->next[first]) node = node->next[first];

        for (int i = 1; i < s; i++) {
            // 자동입력이 불가능한 경우
            // finish = true 이면 '\0' 분기가 하나 더 있는 것이다
            int cnt = node->finish ? node->numNext+1 : node->numNext;
            if (cnt > 1) res++; 

            // 다음 글자로 이동
            int k = word[i] - 'a';
            node = node->next[k];
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (cin >> N) {
        vector<string> words;
        Trie* trie = new Trie();

        for (int i = 0; i < N; i++) {
            string word;
            cin >> word;
            
            words.push_back(word);
            trie->insert(word);
        }

        int total = 0;
        int cnt = words.size();
        for (string &word : words) {
            total += trie->count(word); 
        }
        
        double avg = (double) total / (double) cnt;
        cout << fixed << setprecision(2) << avg << '\n';
        delete trie;
    }

    return 0;
}
