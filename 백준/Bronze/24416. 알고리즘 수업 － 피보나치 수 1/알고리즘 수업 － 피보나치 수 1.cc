#include <bits/stdc++.h>
using namespace std;

int f(int N) {
    int prev = 1, cur = 1;
    for (int i = 0; i < N-2; i++) {
        int next = prev + cur;
        prev = cur; cur = next;
    }
    return cur;
}

int g(int N) {
    return N - 2;
}

int main() {
    int N;
    cin >> N;
    cout << f(N) << ' ' << g(N) << '\n';
    return 0;
}
