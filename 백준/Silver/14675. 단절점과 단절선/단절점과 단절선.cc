#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define For(i, n) for (int i = 0; i < n; i++) 
using namespace std;
using Edge = pair<int,int>;

int N, Q;
const int MAX = 1 << 17;
Edge edges[MAX];

vector<int> tree[MAX];
bool isLeaf[MAX];

int main() {
    FastIO
    cin >> N;

    For(i, N-1) {
        int from, to;
        cin >> from >> to;
        edges[i] = { --from, --to };
        
        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    For(i, N) {
        int size = tree[i].size();
        isLeaf[i] = (size == 1);
    }

    cin >> Q;
    For(i, Q) {
        int T, K;
        cin >> T >> K;
        --T; --K;
        
        bool res = T ? true : !isLeaf[K];
        string ans = res ? "yes" : "no";
        cout << ans << '\n';
    }
    
    return 0;
}
