#include <bits/stdc++.h>
#define SIZE 26
using namespace std;

class Trie {
    private:
    Trie* next[SIZE];
    bool finish;
    int cnt;
    
    public:
    Trie() : finish(false), cnt(0) {
        fill(next, next + SIZE, nullptr);
    }
    
    ~Trie() {
        for (int i = 0; i < SIZE; i++) {
            if (next[i]) delete next[i];
        }
    }
    
    void insert(string &word) {
        Trie* node = this;
        
        for (char letter : word) {
            int k = letter - 'a';
            if (!node->next[k]) {
                node->next[k] = new Trie();
            }
            node = node->next[k];
            node->cnt++;
        }
        
        node->finish = true;
    }
    
    int count(string &word) {
        Trie* node = this;
        int res = -1;
        int s = word.size();
        
        for (int i = 0; i < s; i++) {
            int k = word[i] - 'a';
            
            node = node->next[k];
            if (node->cnt > 1) res = i;
        }
    
        if (res == -1) return 1;
        else if (res == s-1) return s;
        return res + 2;
    }
    
};

int solution(vector<string> words) {
    Trie* trie = new Trie();
    for (string &word : words) {
        trie->insert(word);
    }
    
    int answer = 0;
    for (string &word : words) {
        answer += trie->count(word);
    }
    
    delete trie;
    return answer;
}