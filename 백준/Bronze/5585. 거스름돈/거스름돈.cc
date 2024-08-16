#include <bits/stdc++.h>
using namespace std;

int N, X;

int main() {
    cin >> N;
    N = 1000 - N;

    for (int K : { 500, 100, 50, 10, 5, 1 }) {
        X += N / K;
        N %= K;
    }

    cout << X << '\n';
    return 0;
}
