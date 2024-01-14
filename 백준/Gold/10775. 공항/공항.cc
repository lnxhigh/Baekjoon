#include <iostream>
using namespace std;

int G, P;
int g[100001] = {0};
int gates[100001] = {0};
int cnt = 0;

int find(int x) {
    if (gates[x] == x) return x;
    return gates[x] = find(gates[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (x > y) { gates[x] = y; }
    else { gates[y] = x; }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> G >> P;

    for (int i = 1; i <= G; i++) gates[i] = i;
    for (int i = 1; i <= P; i++) cin >> g[i];
    
    for (int i = 1; i <= P; i++) {
        int k = find(g[i]);
        if (k == 0) break;
        merge(k-1, k);
        cnt++;
    }

    cout << cnt;
    return 0;
}