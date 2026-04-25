#include <iostream>
using namespace std;

int N, r, c;

int count(int N, int r, int c) {
    if (N == 0) return 0;
    int M = 1 << (N-1);
    int quadrant = ((r >= M) << 1) + (c >= M);
    return count(N-1, r % M, c % M) + quadrant * M * M;
}

int main(void) {
    cin >> N >> r >> c;
    cout << count (N, r, c);
}