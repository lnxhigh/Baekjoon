#include <bits/stdc++.h>
using namespace std;

int solve(int N) {
    int len = 0, r = 0;
    vector<bool> visit(N);

    while (++len) {
        r = (10 * r + 1) % N;
        if (r == 0) return len;
        
        if (visit[r]) break;
        visit[r] = true;
    }
    
    return -1;
}

int main() {
    int N; cin >> N;
    int X = solve(N);
    cout << X << '\n';
    return 0;
}
