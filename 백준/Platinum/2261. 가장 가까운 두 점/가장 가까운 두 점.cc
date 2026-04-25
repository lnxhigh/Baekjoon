#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#define MAX 100000

using namespace std;
using xy = pair<int,int>;
int dist(xy a, xy b) {
    int x = a.first - b.first;
    int y = a.second - b.second;
    return x*x + y*y;
}

int N;
xy points[MAX];
int X[MAX];
int Y[MAX];

int closestPair(int* X, int* Y, int n) {
    // Base cases
    if (n == 2) {
        return dist({X[0], Y[0]}, {X[1], Y[1]});
    }
    if (n == 3) {
        return min({ 
            dist({X[0], Y[0]}, {X[1], Y[1]}), 
            dist({X[1], Y[1]}, {X[2], Y[2]}), 
            dist({X[2], Y[2]}, {X[0], Y[0]})
        });
    }

    // Divide
    int mid = n/2;
    int dl = closestPair(X, Y, mid);
    int dr = closestPair(X + mid, Y + mid, n - mid);
    int d = min(dl, dr);

    int delta = floor(sqrt(d));

    // Conquer
    vector<xy> S;
    S.push_back({X[mid], Y[mid]});

    int a = mid-1, b = mid+1;
    while (true) {
        bool checkA = false;
        bool checkB = false;
        if (a >= 0 and X[a] >= X[mid]-delta) {
            S.push_back({X[a], Y[a]});
            a--;
            checkA = true;
        }
        if (b < n and X[b] <= X[mid]+delta) {
            S.push_back({X[b], Y[b]});
            b++;
            checkB = true;
        }

        if (not (checkA or checkB)) break;
    }

    sort(S.begin(), S.end(), [] (xy left, xy right){
        if (left.second < right.second) return true;
        else return false;
    });

    int m = S.size();
    int s = min(m, 7);

    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= min(s,m-i-1); j++) {
            d = min(d, dist(S[i], S[i+j]));
        }
    }

    return d;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;       
        points[i] = { x, y };
    }

    sort(points, points + N);

    for (int i = 0; i < N; i++) {
        X[i] = points[i].first;
        Y[i] = points[i].second;
    }

    int d = closestPair(X, Y, N);
    cout << d;

    return 0;
}