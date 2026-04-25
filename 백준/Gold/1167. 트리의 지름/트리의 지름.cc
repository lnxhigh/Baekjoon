#include <iostream>
#include <vector>
#include <utility>
#define MAX 100001
using namespace std;

struct Tree {
    bool visit = false;
    vector<int> edge;
    vector<int> value;
};

vector<Tree> tree(MAX);

int V;
int x = 0, w = 0;

void dfs(int start, int weight) {
    tree[start].visit = true;
    vector<int> &edge = tree[start].edge;
    vector<int> &value = tree[start].value;

    if (weight > w) {
        w = weight;
        x = start;
    }

    for (int i = 0; i < edge.size(); i++) {
        if (not tree[edge[i]].visit) {
            tree[edge[i]].visit = true;
            dfs(edge[i], weight + value[i]);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> V;

    int end = 0;
    for (int v = 0; v < V; v++) {
        int k, x, w;

        cin >> k;

        while (true) {
            cin >> end;
            if (end == -1) break;
            
            x = end;
            cin >> w;
            
            tree[k].edge.push_back(x);
            tree[k].value.push_back(w);
        }
    }

    dfs(1, 0);
    for (int i = 0; i < MAX; i++) tree[i].visit = false;
    w = 0;
    
    dfs(x, 0);
    cout << w;
    
    return 0;
}