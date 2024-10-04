#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

unordered_set<string> Nickname;

class Trie {
    private:
    
    Trie* next[26];
    bool finish;

    public:

    Trie() : finish(false) {
        fill(next, next + 26, nullptr);
    }

    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (next[i]) delete next[i];
        }
    }

    void insert(const string &name) {
        Trie* trie = this;
        
        for (char x : name) {
            int i = (int) (x - 'a');
            if (!trie->next[i]) trie->next[i] = new Trie();
            trie = trie->next[i];
        }
        
        trie->finish = true;
    }

    bool search(const string &name) {
        Trie* trie = this;

        for (int i = 0; i < (int) name.size(); i++) {
            if (trie->finish && Nickname.count(name.substr(i))) return true;
            int k = (int) name[i] - 'a';
            
            if (!trie->next[k]) break;
            trie = trie->next[k];
        }

        return false;
    }
};

int main() {
    FastIO
    int C, N; cin >> C >> N;
    Trie* trie = new Trie();

    for (int i = 0; i < C; i++) {
        string name; cin >> name;
        trie->insert(name);
    }

    for (int i = 0; i < N; i++) {
        string name; cin >> name;
        Nickname.insert(name);
    }

    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        string name; cin >> name;
        bool found = trie->search(name);
        string ans = found ? "Yes" : "No";
        cout << ans << '\n';
    }

    delete trie;
    return 0;
}
