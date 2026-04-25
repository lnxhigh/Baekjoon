#include <iostream>
#include <cmath>
#define N 11
using namespace std;

int main(void) {
    int arr[N] = {0};
    int T;
    int x;

    cin >> T;
    
    for (int i = 1; i < 4; i++) {
        arr[i] = pow(2, (i-1));
    }
    for (int i = 4; i < N; i++) {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }

    for (int i = 0; i < T; i++) {
        cin >> x;
        cout << arr[x] << endl;
    }

    return 0;
}
