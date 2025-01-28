#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100001;
using int64 = long long;

// Convex Hull Trick
// https://blog.naver.com/kks227/221418495037

struct Line { 
    int64 a, b;
    double o;
    Line(): Line(1, 0) { }
    Line(int64 __a, int64 __b): a(__a), b(__b), o(0) { } 

    double cross(const Line &other) {
        return (double) (other.b - b) / (double) (a - other.a);
    }
};

int64 N;
int64 A[MAX], B[MAX];
int64 D[MAX];
Line F[MAX];

int main(){
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
 
    int top = 0;
    for (int i = 1; i < N; i++){
        Line line(B[i - 1], D[i - 1]);
        while (top) {
            line.o = line.cross(F[top - 1]);
            if (F[top - 1].o < line.o) break;
            else top--;
        }
        F[top++] = line;
 
        int64 x = A[i];
        int idx = -1;
        int low = 0, high = top - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (x >= F[mid].o) idx = mid, low = mid + 1;
            else high = mid - 1;
        }
        
        assert(idx != -1);
        D[i] = F[idx].a * x + F[idx].b;
    }
    
    cout << D[N - 1] << '\n';
    return 0;
}
