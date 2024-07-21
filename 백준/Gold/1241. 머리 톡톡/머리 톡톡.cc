#include <bits/stdc++.h>
using namespace std;

int N;
int H[1 << 17];
int X[1 << 20];

int Count[1 << 20];
bool Processed[1 << 20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> H[i];
    for (int i = 0; i < N; i++) Count[H[i]]++;
    int K = *max_element(H, H + N);

    for (int i = 0; i < N; i++) {
        if (Processed[H[i]]) continue;
        Processed[H[i]] = true;

        for (int j = H[i]; j <= K; j += H[i]) {
            X[j] += Count[H[i]];
        }
    }

    for (int i = 0; i < N; i++) {
        cout << X[H[i]] - 1 << '\n';
    }
    return 0;
}
