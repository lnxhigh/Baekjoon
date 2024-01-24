#include <iostream>
#include <utility>
#define ll long long
#define X first
#define Y second

using namespace std;
using point = pair<ll,ll>;

int ccw(point A, point B, point C) {
    int dir;
    ll x1 = A.X, y1 = A.Y;
    ll x2 = B.X, y2 = B.Y;
    ll x3 = C.X, y3 = C.Y;
    
    ll det = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
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

int main(void) {
    point A, B, C, D;
    cin >> A.X >> A.Y >> B.X >> B.Y;
    cin >> C.X >> C.Y >> D.X >> D.Y;

    if (A > B) swap(A, B);
    if (C > D) swap(C, D);

    int abc = ccw(A, B, C), abd = ccw(A, B, D);
    int cda = ccw(C, D, A), cdb = ccw(C, D, B);

    int res;
    int l = abc * abd, r = cda * cdb;

    if (l == 0 and r == 0) res = (A <= D and C <= B);
    else res = (l <= 0 and r <= 0);
    
    cout << res << '\n';

    return 0;
}