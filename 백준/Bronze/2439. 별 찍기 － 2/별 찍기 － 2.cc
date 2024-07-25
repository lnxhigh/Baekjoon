#include <bits/stdc++.h>
using namespace std;

int N;
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cout << string(N-i, ' ') << string(i, '*') << '\n';
    }
    return 0;
}
