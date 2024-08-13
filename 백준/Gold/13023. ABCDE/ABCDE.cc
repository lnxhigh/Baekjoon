#include <bits/stdc++.h>
using namespace std;

int V, E;
const int MAX = 1 << 11;
vector<int> graph[MAX];
bool exist = false;

void dfs(int X, vector<int> &friends) {
    if (exist) return;

    int connection = friends.size();
    if (connection == 4) {
        exist = true;
        return;
    }

    for (int k : graph[X]) {
        bool check = true;
        for (int i : friends) {
            if (k == i) {
                check = false;
                break;
            }
        }
        if (!check) continue;

        friends.push_back(X);
        dfs(k, friends);
        friends.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> friends;
    for (int i = 0; i < V; i++) {
        dfs(i, friends);
    }

    cout << exist << '\n';

    return 0;
}
