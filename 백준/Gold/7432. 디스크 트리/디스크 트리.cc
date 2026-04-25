#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

class Directory {
    public:
    string name;
    map<string,Directory*> dirs;

    Directory(string __name): name(__name) {}
    ~Directory() { for (auto& [dirname, dir] : dirs) dirs.erase(dirname); }

    void insert(string path) {
        int pos = -1;
        Directory* cur = this;

        while ((pos = path.find('\\')) != string::npos) {
            string dirname = path.substr(0, pos);
            path = path.substr(pos + 1);
            if (!cur->dirs.count(dirname)) {
                cur->dirs[dirname] = new Directory(dirname);
            }
            cur = cur->dirs[dirname];
        }

        if (!cur->dirs.count(path)) {
            cur->dirs[path] = new Directory(path);
        }
    }

    void print(int depth) {
        if (depth >= 0) {
            cout << string(depth, ' ') << name << '\n';
        }
        for (const auto& [dirname, dir] : dirs) {
            dir->print(depth + 1);
        }
    }
};

int main() {
    FastIO
    int N; cin >> N;
    
    Directory* root = new Directory("");
    while (N--) {
        string path; cin >> path;
        root->insert(path);
    }

    root->print(-1);
    return 0;
}
