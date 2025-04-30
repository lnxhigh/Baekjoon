#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

class Directory {
public:
    string name;
    string parent;
    map<string,Directory*> next;
    set<string> files;
};

int n, m, k, q;
map<string,Directory*> all;

int main() {
    FastIO
    cin >> n >> m;

    for (int i = 0; i < n + m; i++) {
        string p, f; cin >> p >> f;
        bool c; cin >> c;

        Directory* dir = nullptr;
        if (all.count(p)) dir = all[p];
        else dir = new Directory(), dir->name = p, all[p] = dir;
        
        if (c == 1) {
            Directory* child = nullptr;
            if (all.count(f)) child = all[f];
            else child = new Directory(), child->name = f, all[f] = child;

            child->parent = p;
            dir->next[f] = child;
        }
        else {
            dir->files.insert(f);
        }
    }
    
    cin >> k;

    while (k--) {
        string path;
        string src_path, dst_path; cin >> src_path >> dst_path;
        stringstream ss_src(src_path);
        stringstream ss_dst(dst_path);

        while (getline(ss_src, path, '/'));
        Directory* src = all[path];
        assert(src);

        while (getline(ss_dst, path, '/'));
        Directory* dst = all[path];
        assert(dst);

        for (auto& [name, dir] : src->next) {
            dir->parent = dst->name;
            dst->next[name] = move(dir);
        }
        for (auto& name : src->files) {
            dst->files.insert(name);
        }

        Directory* par = all[src->parent];
        assert(par);
        
        par->next.erase(src->name);
        all.erase(src->name);
    }

    cin >> q;

    while (q--) {
        string path; cin >> path;
        stringstream ss(path);
        while (getline(ss, path, '/'));

        Directory* dir = all[path];
        assert(dir);

        set<string> files;
        int types = 0;
        int cnt = 0;
        
        stack<Directory*> st;
        st.push(dir);

        while (!st.empty()) {
            Directory* cur = st.top();
            st.pop();

            for (const auto& [name, next] : cur->next) {
                st.push(next);
            }
            for (const string& file : cur->files) {
                files.insert(file);
                cnt++;
            }
        }

        types = (int) files.size();
        cout << types << ' ' << cnt << '\n';
    }
    
    return 0;
}
