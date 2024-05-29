#include <bits/stdc++.h>
#define N_MAX 50
#define ll long long
using namespace std;

int N;
int heights[N_MAX];
int buildings[N_MAX];

bool see(int from, int to) {
    // Assume from < to
    if (to - from == 1) return true;
    
    for (int i = from+1; i < to; i++) {
        int x1 = i - from;
        int h1 = heights[i] - heights[from];
        int x2 = to - i;
        int h2 = heights[to] - heights[i];

        if (1LL * h1 * x2 >= 1LL * h2 * x1) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (see(i, j)) {
                buildings[i]++;
                buildings[j]++;
            }
        }
    }
    
    int answer = buildings[0];
    for (int i = 0; i < N; i++) {
        if (answer < buildings[i]) answer = buildings[i];
    }
    
    cout << answer << '\n';

    return 0;
}
