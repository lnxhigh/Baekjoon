#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100000;

int V, E;
pair<int,int> Edges[MAX << 1];

vector<int> graph[MAX];
vector<int> tree[MAX];
bool visited[MAX];

vector<int> fail = { -2 };

void print(vector<int> &vec) {
    for (int i : vec) cout << i + 1 << ' ';
    cout << '\n';
}

void input() {
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int x, y; cin >> x >> y; --x, --y;
        Edges[i] = { x, y };
        graph[x].push_back(i);
        graph[y].push_back(i);
    }
}

void dfs(int cur, vector<int> &v, vector<int> &e) {
    visited[cur] = true;
    v.push_back(cur);

    for (int i : graph[cur]) {
        auto [x, y] = Edges[i];
        int nxt = (x != cur) ? x : y;

        if (!visited[nxt]) {
            tree[cur].push_back(i);
            e.push_back(i);
            dfs(nxt, v, e);
        }
    }
}

pair<int,int> fall(vector<int> &v, vector<int> &e) {
    int leaf = -1;
    for (int i : v) {
        if (tree[i].empty()) {
            leaf = i;
            break;
        }
    }
    
    int edge = -1;
    for (int i : e) {
        auto [x, y] = Edges[i];
        if (x == leaf || y == leaf) {
            edge = i;
            break;
        }
    }

    return { leaf, edge };
}

void remove_value(vector<int> &vec, int value) {
    vec.erase(remove(vec.begin(), vec.end(), value), vec.end());
}

void solve() {
    if (V <= 2) { 
        print(fail);
        return; 
    }

    vector<vector<int>> vs, es;
    for (int i = 0; i < V; i++) {
        if (visited[i]) continue;

        vector<int> v, e;
        dfs(i, v, e);
        vs.push_back(v);
        es.push_back(e);
    }
    int cnt = vs.size();

    if (cnt >= 3) {
        print(fail); 
        return;
    }
    else if (cnt == 2) {
        if (vs[0].size() == vs[1].size()) {
            print(fail); 
            return;
        }
    }
    else if (cnt == 1) {
        auto [leaf, edge] = fall(vs[0], es[0]);
        assert(leaf != -1 && edge != -1);

        remove_value(vs[0], leaf);
        remove_value(es[0], edge);

        vector<int> newv = { leaf };
        vector<int> newe;

        vs.push_back(newv);
        es.push_back(newe);
    }
    
    assert((int) vs[0].size() + (int) vs[1].size() == V);
    cout << vs[0].size() << ' ' << vs[1].size() << '\n';
    
    assert((int) vs[0].size() - 1 == (int) es[0].size());
    print(vs[0]); print(es[0]);

    assert((int) vs[1].size() - 1 == (int) es[1].size());
    print(vs[1]); print(es[1]);
}

int main() {
    FastIO
    input();
    solve();
    return 0;
}
