#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 6;
int N, M; 
vector<set<int>> tree;
vector<set<int>> newTree; // copy
multiset<int> family;

pair<int,int> dfs(int cur, vector<bool> &visit) {
    int total = 1;
    int cnt = family.count(cur);

    visit[cur] = true;
    
    for (int next : newTree[cur]) {
        if (visit[next]) continue;
        auto [ total_, cnt_ ] = dfs(next, visit);
        
        total += total_;
        cnt += cnt_;
    }

    return { total, cnt };
}

int main() {

    // Input
    
    FastIO
    cout << setprecision(16);

    cin >> N >> M;
    tree.resize(N);
    newTree.resize(N);

    for (int i = 0; i < N - 1; i++) {
        int x, y; cin >> x >> y;

        tree[x].insert(y);
        tree[y].insert(x);
        
        newTree[x].insert(y);
        newTree[y].insert(x);
    }

    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        family.insert(x);
    }

    // Count

    double res = 0;
    for (int cur = 0; cur < N; cur++) {
        for (int next : tree[cur]) {
            if (cur > next) continue;
            
            vector<bool> visit(N);
            
            newTree[next].erase(cur);
            newTree[cur].erase(next);
            
            auto [ x, a ] = dfs(cur, visit);
            auto [ y, b ] = dfs(next, visit);

            newTree[cur].insert(next);
            newTree[next].insert(cur);

            double p = a * log(y) + b * log(x) - M * log(N - 1);
            res += exp(p);
        }
    }

    cout << res << '\n';
    return 0;
}
