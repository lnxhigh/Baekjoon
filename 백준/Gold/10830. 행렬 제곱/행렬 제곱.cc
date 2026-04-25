#include <iostream>
#define MAX 5
#define K 1000
#define ll long long
using namespace std;

int N;
ll B;

struct matrix { 
    int data[MAX][MAX] = {0,}; 
};

matrix operator* (const matrix& left, const matrix& right) {
    matrix result;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result.data[i][j] += left.data[i][k] * right.data[k][j];
            }
            result.data[i][j] %= K;
        }
    }
    
    return result;
}

matrix operator^ (const matrix& m, ll p) {
    if (p == 1LL) { 
        matrix eye;
        for (int i = 0; i < N; i++) eye.data[i][i]++;
        return m * eye;
    }
    
    matrix x = m ^ (p / 2LL);
    if (p % 2LL == 0LL) return x * x;
    else return x * x * m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> B;
    
    matrix A;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A.data[i][j];
        }
    }

    matrix C = A ^ B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << C.data[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}