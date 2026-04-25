#include <iostream>

using namespace std;

int T;
int a, b;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int remain[10][4];
    int digit;

    for (b = 0; b < 4; b++) {
        remain[0][b] = 10;
    }

    for (a = 1; a < 10; a++) {
        digit = 1;
        for (b = 0; b < 4; b++) {
            digit = (digit * a) % 10;
            remain[a][(b+1)%4] = digit;
        }
    }

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> a >> b;

        digit = remain[a %= 10][b %= 4]; 
        cout << digit << '\n';
    }

    return 0;
}