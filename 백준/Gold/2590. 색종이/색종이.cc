#include <bits/stdc++.h>
using namespace std;
int A[7];

int main() {
    for (int i = 1; i <= 6; i++) {
        cin >> A[i];
    }
    
    int ans = 0;
    int one = 0, two = 0, three = 0;

    // Six
    ans += A[6];
    
    // Five
    ans += A[5];
    one += 11 * A[5];

    // Four
    ans += A[4];
    two += 5 * A[4]; 

    // Three
    ans += (A[3] + 3) / 4;
    A[3] %= 4;
    if (A[3] != 0) {
        three += 4 - A[3];
    }

    // Two
    if (three == 3) {
        two += 5;
        one += 7;
    }
    else if (three == 2) {
        two += 3;
        one += 6;
    }
    else if (three == 1) {
        two += 1;
        one += 5;
    }

    if (A[2] <= two) {
        two -= A[2];
        one += two * 4;
    }
    else {
        A[2] -= two;
        two = 0;

        ans += (A[2] + 8) / 9;
        A[2] %= 9;
        if (A[2] != 0) {
            two += 9 - A[2];
        }
        one += two * 4;
    }

    // One
    if (A[1] > one) {
        A[1] -= one;
        ans += (A[1] + 35) / 36;
    }

    cout << ans << '\n';
    return 0;
}
