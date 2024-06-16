#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using Point = pair<double,double>;

const int N = 8;
const double V = 0.70710678118654752440;

int ability[N];
double cosValue[8] = { 1, V, 0, -V, -1, -V, 0, V };
double sinValue[8] = { 0, V, 1, V, 0, -V, -1, -V };

int answer = 0;

int ccw(Point A, Point B, Point C) {
    double x1 = B.X - A.X, y1 = B.Y - A.Y;
    double x2 = C.X - A.X, y2 = C.Y - A.Y;
    double det = x1*y2 - x2*y1;
    
    int dir = 0;
    if (det > 0) dir = 1;
    else if (det < 0) dir = -1;
    else dir = 0;
    
    return dir;
}

bool isConvex(vector<int> &perm) {
    for (int i = 0; i < N; i++) {
        Point P[3];
        for (int k = 0; k < 3; k++) {
            double x = ability[perm[(i+k) % N]] * cosValue[(i+k) % N];
            double y = ability[perm[(i+k) % N]] * sinValue[(i+k) % N];
            P[k] = { x, y };
        }
        
        if (ccw(P[0], P[1], P[2]) < 0) return false;
    }

    return true;
}

void dfs(vector<int> &permutation) {
    if (permutation.size() == N) {
        if (isConvex(permutation)) {
            answer++;
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        bool check = true;
        for (int k : permutation) {
            if (k == i) {
                check = false;
                break;
            }
        }

        if (check) {
            permutation.push_back(i);
            dfs(permutation);
            permutation.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < N; i++) {
        cin >> ability[i];
    }

    vector<int> permutation;
    dfs(permutation);
    cout << answer << '\n';

    return 0;
}
