#include <bits/stdc++.h>
using namespace std;

int main() {
    int K; cin >> K;
    int i = 0;
    while (K >= (1 << i)) K -= 1 << i++;
    while (i--) cout << (K >> i & 1 ? '7' : '4');
}
