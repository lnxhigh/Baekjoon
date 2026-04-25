#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_V 10000
#define MAX_E 100000

using namespace std;

int V, E;
vector<int> A(MAX_E), B(MAX_E), W(MAX_E);

int parent[MAX_V];
int index[MAX_E];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

// Kruskal's algorithm
int main (void) {
    int x, y, z;
    int weight = 0;
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> V >> E;

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < E; i++) {
        index[i] = i;
        cin >> x >> y >> z;
        A[i] = x-1; B[i] = y-1; W[i] = z;
    }

    sort(index, index + E, [&](int i, int j) {
        return W[i] < W[j];
    });

    for (int i = 0; i < E; i++) {
        z = index[i];
        x = find(A[z]);
        y = find(B[z]);

        if (x != y) { // if it does not form a cycle
            parent[y] = x; // union
            weight += W[z];
        }
    }

    cout << weight;

    return 0;
}