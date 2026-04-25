#include <iostream>
#define MAX 1000001

using namespace std;

int n, m;
int op, a, b;
int parent[MAX];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> op >> a >> b;
        if (op) {
            cout << ((find(a) == find(b)) ? "yes" : "no") << '\n';
        }
        else {
            merge(a, b);
        }
    }

    return 0;
}