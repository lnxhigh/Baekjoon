#include <iostream>
#include <algorithm>
#define N_MAX 100001
using namespace std;

struct Point {
    int index;
    int x, y, z;
};
struct Delta {
    int a, b;
    int delta;
};


int N;
int parent[N_MAX];
Point planet[N_MAX];
Delta diff[N_MAX * 3];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
int Abs(int x) { return x > 0 ? x : -x ; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    int V = N, E = 3*N-3;

    for (int i = 0; i < V; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        planet[i] = { i, x, y, z };
    }

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }
    
    sort(planet, planet+N, [](Point A, Point B) {
        if (A.x < B.x) return true;
        else return false;
    });
    for (int i = 0; i < N-1; i++) {
        diff[i] = {
            planet[i].index, planet[i+1].index,
            Abs(planet[i+1].x - planet[i].x)
        };
    }

    sort(planet, planet+N, [](Point A, Point B) {
        if (A.y < B.y) return true;
        else return false;
    });
    for (int i = 0; i < N-1; i++) {
        diff[N-1+i] = {
            planet[i].index, planet[i+1].index,
            Abs(planet[i+1].y - planet[i].y)
        };
    }
    
    sort(planet, planet+N, [](Point A, Point B) {
        if (A.z < B.z) return true;
        else return false;
    });
    for (int i = 0; i < N-1; i++) {
        diff[2*N-2+i] = {
            planet[i].index, planet[i+1].index,
            Abs(planet[i+1].z - planet[i].z)
        };
    }

    sort(diff, diff + E, [](Delta A, Delta B) {
        if (A.delta < B.delta) return true;
        else return false;
    });

    int cost = 0;
    for (int i = 0; i < E; i++) {
        Delta k = diff[i];
        int x = find(k.a);
        int y = find(k.b);

        if (x != y) {
            parent[y] = x;
            cost += k.delta;
        }
    }

    cout << cost << '\n';

    return 0;
}
