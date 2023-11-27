#include <iostream>
#include <iomanip>
#define ll long long
#define N_MAX 10000

using namespace std;

struct Point {
    ll x;
    ll y;
};

ll N;
ll x, y;
Point point[N_MAX];

ll cross(Point A, Point B, Point C) {
    return (A.x-B.x)*(A.y-C.y) - (A.x-C.x)*(A.y-B.y);
}
ll Abs(ll x) {
    return x > 0LL ? x : -x ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N; i ++) {
        cin >> x >> y;
        point[i] = { x, y };
    }

    ll area = 0;
    for (int i = 1; i+1 < N; i++) area += cross(point[0], point[i], point[i+1]);
    area = Abs(area);
    cout << fixed << setprecision(1) << area * 0.5L << '\n';
    
    return 0;
}