#include <iostream>
#include <utility>
#define N_MAX 3001
#define X first
#define Y second

using namespace std;
using point = pair<int,int>;
using line = pair<point,point>;

int N;
line lines[N_MAX];
int parent[N_MAX];
int group[N_MAX] = {0,};

int ccw(point A, point B, point C) {
    int dir;
    int x1 = A.X, y1 = A.Y;
    int x2 = B.X, y2 = B.Y;
    int x3 = C.X, y3 = C.Y;
    
    int det = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (det > 0) dir = 1;
    else if (det < 0) dir = -1;
    else dir = 0;

    return dir;
} 

void swap(point &A, point &B) {
    point temp;
    temp = A;
    A = B;
    B = temp;
    return;
}

int check(line first, line second) {
    int res;

    point A = first.X, B = first.Y;
    point C = second.X, D = second.Y;

    if (A > B) swap(A, B);
    if (C > D) swap(C, D);

    int abc = ccw(A, B, C), abd = ccw(A, B, D);
    int cda = ccw(C, D, A), cdb = ccw(C, D, B);
    int l = abc * abd, r = cda * cdb;

    if (l == 0 and r == 0) res = (A <= D and C <= B);
    else res = (l <= 0 and r <= 0);

    return res;
}

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    
    if (x > y) parent[x] = y;
    else parent[y] = x;
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        point A, B;
        cin >> A.X >> A.Y;
        cin >> B.X >> B.Y;
        lines[i] = { A, B };
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i+1; j <= N; j++) {
            if (check(lines[i], lines[j])) {
                merge(i, j);
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        group[find(i)]++;
    }

    int n_group = 0;
    for (int i = 1; i <= N; i++) {
        if (group[i] > 0) n_group++;
    }
    
    int size_largest_group = 0;
    for (int i = 1; i <= N; i++) {
        if (group[i] > size_largest_group) size_largest_group = group[i];
    }

    cout << n_group << '\n';
    cout << size_largest_group << '\n';

    return 0;
}