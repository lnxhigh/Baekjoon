#include <iostream>
#define MAX 10001
using namespace std;

int N, x;
int count[MAX] = {0,};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        count[x]++;
    }
    for (int i = 0; i < MAX; i++) {
        for (int k = 0; k < count[i]; k++) {
            cout << i << '\n';
        }
    }
}