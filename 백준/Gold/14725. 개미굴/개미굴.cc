#include <bits/stdc++.h>
#define K_MAX
using namespace std;

int N, K;
string S;

class Trie {
    map<string,Trie*> go;
    bool finish;
    
    public:
    Trie() {
        finish = false;
    }

    ~Trie() {
        for (pair<string,Trie*> p : go) {
            delete p.second;
        }
        go.clear();
    }

    void insert(vector<string> &strings) { insert(0, strings); }
    void print() { print(0); }

    void insert(int i, vector<string> &strings) {
        if (i == strings.size()) {
            finish = true;
            return;
        }
        
        string next = strings[i];
        if (!go.count(next)) go[next] = new Trie();
        go[next]->insert(i+1, strings);
    }

    void print(int i) {
        if (finish) return;
        for (pair<string,Trie*> p : go) {
            cout << string(i << 1, '-') << p.first << '\n';
            p.second->print(i+1);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    Trie* trie = new Trie();

    for (int i = 0; i < N; i++) {
        cin >> K;
        vector<string> strings;
        for (int k = 0; k < K; k++) {
            cin >> S;
            strings.push_back(S);
        }
        trie->insert(strings);
    }

    trie->print();
    delete trie;
    
    return 0;
}
