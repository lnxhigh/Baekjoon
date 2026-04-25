#include <iostream>

using namespace std;

int N;

void print(int N) {
    if (N == 0) {
        cout << '-';
        return;
    }
    else {
        print(N-1);
        int M = 1;
        for (int i = 0; i < N-1; i++) { M *= 3; }
        for (int i = 0; i < M; i++) { cout << ' '; }
        print(N-1);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (true) {
        cin >> N;
        if (cin.eof() == true) { break; }
        print(N);
        cout << '\n';
    }

    return 0;
}