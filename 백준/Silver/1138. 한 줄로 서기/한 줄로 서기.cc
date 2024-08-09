#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 1 << 4;
int H[N_MAX];

int L[N_MAX];
bool isFinished = false;


void f(int k, int s) {
    if (isFinished) return;
    
    if (k == N) {
        // Check if the height sequence is valid
        for (int i = 0; i < N; i++) {
            int cnt = 0;
            for (int x = 0; x < i; x++) {
                if (L[x] > L[i]) cnt++;
            }
            if (cnt != H[L[i]]) return;
        }

        // Finish
        isFinished = true;
        for (int i = 0; i < N; i++) {
            cout << L[i] + 1 << ' ';
        }
        cout << '\n';
        
        return;
    }

    for (int i = 0; i < N; i++) {
        // return if the person is already selected
        // return if the selection is impossible
        if ((s & (1 << i)) || k < H[i]) continue;
        
        // Mark as selected and proceed to next step
        L[k] = i;
        f(k + 1, s | (1 << i));
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> H[i];
    f(0, 0);
    return 0;
}
