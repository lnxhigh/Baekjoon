#include <bits/stdc++.h>
using namespace std;

int N, X;
int bits[20] = {0,};
int answer = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X; 
        int p = 0;
        while (X) {
            if (X & 1) bits[p]++;
            X = X >> 1; p++;
        }
    }

    for (int i = 0; i < 20; i++) {
        if (bits[i] > answer) answer = bits[i];
    }
    cout << answer << '\n';

    return 0;
}
