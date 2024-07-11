#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 1000001;
vector<int> hexa;

int D[N_MAX];

// 약간 느려서 시간초과될 것 같아 아쉽다
// 10만 정도까지는 괜찮을듯

int main() {
    cin >> N;

    int x = 0;
    while (++x) {
        int k = x * 2 - 1;
        int num = k * (k+1) / 2;
        if (num > N_MAX) break;
        
        hexa.push_back(num);
    }

    fill(D + 1, D + N_MAX, 1 << 3);
    for (int i = 1; i <= N; i++) {
        int k = upper_bound(hexa.begin(), hexa.end(), i) - hexa.begin();
        for (int j = 0; j < k; j++) {
            D[i] = min(D[i], D[i - hexa[j]] + 1);
        }
    }

    cout << D[N] << '\n';
    return 0;
}
