#include <iostream>
using namespace std;

int N, M;
int x, y, z;
int cards[101];
int Max(int x, int y) { return x > y ? x : y ; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }

    int sum = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j == i) continue;
            for (int k = 0; k < N; k++) {
                if (k == j or k == i) continue;

                if (cards[i] + cards[j] + cards[k] <= M) {
                    sum = Max(sum, cards[i] + cards[j] + cards[k]);
                }
            }
        }
    }
    
    cout << sum;

    return 0;
}