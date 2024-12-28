#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

struct File {
    string name;
    File() { }
    File(string __name): name(__name) { }
};

class Directory {
    public:

    string name;
    Directory* parent;
    map<string,Directory*> dirs;
    map<string,File> files;
    
    Directory(string __name): name(__name) {
        parent = nullptr;
    }

    ~Directory() {
        dirs.clear();
        files.clear();
    }

    bool mkdir(string dirname) {
        if (dirs.count(dirname)) return false;
        Directory* newDir = new Directory(dirname);
        newDir->parent = this;
        dirs[dirname] = newDir;
        return true;
    }

    pair<int,int> rmdir(string dirname) {
        if (dirs.empty()) return { 0, 0 };

        if (dirname == "0") {
            int dirs_cnt = 0, files_cnt = 0;
            for (auto& [childname, dir] : dirs) {
                dirs_cnt  += dirs[childname]->count_dirs();
                files_cnt += dirs[childname]->count_files();
            }
            dirs.clear();

            return { dirs_cnt, files_cnt };
        }

        if (dirname == "-1") dirname = (*dirs.begin()).first;
        else if (dirname == "1") dirname = (*dirs.rbegin()).first;
        if (dirs.find(dirname) == dirs.end()) return { 0, 0 };

        int dirs_cnt  = dirs[dirname]->count_dirs();
        int files_cnt = dirs[dirname]->count_files();
        
        dirs.erase(dirname);
        return { dirs_cnt, files_cnt };
    }

    bool insert(string filename) {
        if (files.count(filename)) return false;

        File file = File(filename);
        files[filename] = file;
        return true;
    }

    int del(string filename) {
        if (files.empty()) return 0;

        if (filename == "0") {
            int cnt = (int) files.size();
            files.clear();
            return cnt;
        }

        if (filename == "-1") filename = (*files.begin()).first;
        else if (filename == "1") filename = (*files.rbegin()).first;
        if (files.find(filename) == files.end()) return 0;

        files.erase(filename);
        return 1;
    }

    int count_dirs() {
        int cnt = 1;
        for (auto [dirname, child] : dirs) {
            cnt += child->count_dirs();
        }
        return cnt;
    }

    int count_files() {
        int cnt = files.size();
        for (auto [dirname, child] : dirs) {
            cnt += child->count_files();
        }
        return cnt;
    }
};

class Command {
    public:
    Directory* cur;

    Command() { 
        Directory* root = new Directory("album");
        cur = root;
    }

    ~Command() { 

    }

    bool mkdir(string dirname) {
        return cur->mkdir(dirname);
    }

    pair<int,int> rmdir(string dirname) {
        return cur->rmdir(dirname);
    }

    bool insert(string filename) {
        return cur->insert(filename);
    }

    int del(string filename) {
        return cur->del(filename);
    }

    string chdir(string dirname) {
        if (dirname == "/") {
            while (cur->parent) {
                cur = cur->parent;
            }
        }
        else if (dirname == "..") {
            if (cur->parent) {
                cur = cur->parent;
            }
        }
        else {
            if (cur->dirs.count(dirname)) {
                cur = cur->dirs[dirname];
            }
        }

        return cur->name;
    }
};

int main() {
    FastIO
    int N; cin >> N;
    Command *cmd = new Command();

    while (N--) {
        string prompt, arg;
        cin >> prompt >> arg;

        if (prompt == "mkalb") {
            bool success = cmd->mkdir(arg);
            if (!success) cout << "duplicated album name" << '\n';
        }
        else if (prompt == "rmalb") {
            auto [albums, photos] = cmd->rmdir(arg);
            cout << albums << ' ' << photos << '\n';
        }
        else if (prompt == "insert") {
            bool success = cmd->insert(arg);
            if (!success) cout << "duplicated photo name" << '\n';
        }
        else if (prompt == "delete") {
            int cnt = cmd->del(arg);
            cout << cnt << '\n';
        }
        else if (prompt == "ca") {
            string dirname = cmd->chdir(arg);
            cout << dirname << '\n';
        }
    }
    
    return 0;
}
