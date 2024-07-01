#include <bits/stdc++.h>
using namespace std;

int TC;
int N;
const int N_MAX = 10000;

vector<string> phones;

//215

class Trie {
    private:
        Trie* next[10];
        bool finish;

    public:
    
    Trie() : finish(false) { 
        for (int i = 0; i < 10; i++) {
            next[i] = nullptr;
        }
    }

    ~Trie() {
        for (int i = 0; i < 10; i++) {
            if (next[i]) delete next[i];
        }
    }

    void insert(string phone) {
        Trie* node = this;
        for (char c : phone) {
            int k = c - '0';
            if (!node->next[k]) node->next[k] = new Trie();
            node = node->next[k];
        }
        node->finish = true;
    }

    bool check(string phone) {
        Trie* node = this;
        for (char c : phone) {
            int k = c - '0';
            
            if (node->finish) return false;
            node = node->next[k];
        }

        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> TC;

    while (TC--) {
        cin >> N;
        phones.clear();
        phones.reserve(N_MAX);
        
        for (int i = 0; i < N; i++) {
            string phone;
            cin >> phone;
            phones.push_back(phone);
        }

        Trie* trie = new Trie();
        for (string phone : phones) {
            trie->insert(phone);
        }

        bool res = true;
        for (string phone : phones) {
            if (!trie->check(phone)) {
                res = false;
                break;
            }
        }

        string ans = res ? "YES" : "NO";
        cout << ans << '\n';
        delete trie;
    }

    return 0;
}
