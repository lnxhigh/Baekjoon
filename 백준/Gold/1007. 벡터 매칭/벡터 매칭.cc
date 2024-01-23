#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <iomanip>
#include <float.h>
#define X first
#define Y second
using namespace std;

int T;

pair<int,int> operator+(pair<int,int> &left, pair<int,int> &right) {
    return { left.X + right.X, left.Y + right.Y };
}
pair<int,int> operator-(pair<int,int> &left, pair<int,int> &right) {
    return { left.X - right.X, left.Y - right.Y };
}
void operator+=(pair<int,int> &left, pair<int,int> &right) {
    left.X += right.X;
    left.Y += right.Y;
}
double length(pair<int,int> point) {
    double x = double(point.X), y = double(point.Y);
    return sqrt(x*x + y*y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> T;
    while (T--) {
        int N;
        int x, y;
        pair<int,int> points[20];

        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> x >> y;
            points[i] = {x,y};
        }

        int combinatc[200000];
        int len = 0;
        
        for (int i = 0; i < (1 << N); i++) {
            int cnt = 0;
            for (int k = 0; k < N; k++) {
                if (i & (1 << k)) cnt++;
            }
            if (cnt == (N >> 1)) combinatc[len++] = i;
        }
        
        double distance = DBL_MAX;
        for (int i = 0; i < len; i++) {
            int bit = combinatc[i];
            pair<int,int> v1 = {0,0}, v2 = {0,0};

            for (int k = 0; k < N; k++) {
                if (bit & (1 << k)) v1 += points[k];
                else v2 += points[k];
            }
            
            double new_distance = length(v1 - v2);
            if (new_distance < distance) distance = new_distance;
        }
        cout << fixed << setprecision(12) << distance << '\n';
    }
    
    return 0;
}