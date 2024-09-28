#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, N; 
    cin >> A >> B >> N;
    A %= B;
    while (--N) A = 10 * A % B;
    cout << 10 * A / B << '\n';
    return 0;
}
