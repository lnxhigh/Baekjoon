#include <iostream>
#define ll long long
#define K 1000000007LL
using namespace std;

ll N;

struct mat2 { 
    ll data[4]; 
};

mat2 operator* (const mat2& left, const mat2& right) {
    mat2 result;
    result.data[0] = (left.data[0]*right.data[0] + left.data[1]*right.data[2]) % K;
    result.data[1] = (left.data[0]*right.data[1] + left.data[1]*right.data[3]) % K;
    result.data[2] = (left.data[2]*right.data[0] + left.data[3]*right.data[2]) % K;
    result.data[3] = (left.data[2]*right.data[1] + left.data[3]*right.data[3]) % K;
    
    return result;
}

mat2 operator^ (const mat2& m, ll p) {
    if (p == 1LL) return m;
    
    mat2 x = m ^ (p / 2LL);
    if (p % 2LL == 0LL) return x * x;
    else return x * x * m;
}

int main () {
    cin >> N;
    mat2 m = { {1LL, 1LL, 1LL, 0LL} };
    cout << (m ^ N).data[2];
}