#include <iostream>
#define MAX_N 500000
using namespace std;

int n, m;
int x, y;
int parent[MAX_N];
int answer = 0;
bool finish = false;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        if (finish) continue;
        
        x = find(x);
        y = find(y);
        if (x == y) {
            answer = i;
            finish = true;
            continue;
        }
        
        if (x < y) parent[y] = x;
        else parent[x] = y;
    }

    cout << answer << '\n';

    return 0;
}