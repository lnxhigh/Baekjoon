#include <bits/stdc++.h>
#define N_MAX 10001
using namespace std;

int T;
vector<int> tree[N_MAX];
int parent[N_MAX];

int LCA(int u, int v) {
    vector<int> pathU, pathV;
    for (int k = u; k != 0; k = parent[k]) {
        pathU.push_back(k);
    }
    for (int k = v; k != 0; k = parent[k]) {
        pathV.push_back(k);
    }
    
    reverse(pathU.begin(), pathU.end());
    reverse(pathV.begin(), pathV.end());
    int s = min(pathU.size(), pathV.size());

    int res = pathU[0];
    for (int i = 0; i < s; i++) {
        if (pathU[i] == pathV[i]) res = pathU[i];
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;

        for (int i = 0; i < N_MAX; i++) tree[i].clear();
        fill(parent, parent + N_MAX, 0);

        for (int i = 0; i < N-1; i++) {
            int A, B;
            cin >> A >> B;
            tree[A].push_back(B);
            parent[B] = A;
        }

        int U, V;
        cin >> U >> V;

        int answer = LCA(U, V);
        cout << answer << '\n';
    }

    return 0;
}
