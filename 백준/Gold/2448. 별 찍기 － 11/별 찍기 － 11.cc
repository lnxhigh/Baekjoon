#include <iostream>
using namespace std;

int N;
char arr[3072+1][6144+1];

void star(int N, int r, int c, char arr[3072+1][6144+1]) {
    if (N == 3) {
        arr[r-1][c] = '*';

        arr[r][c+1] = '*';
        arr[r][c-1] = '*';
        
        arr[r+1][c] = '*';
        arr[r+1][c+1] = '*';
        arr[r+1][c-1] = '*';
        arr[r+1][c+2] = '*';
        arr[r+1][c-2] = '*';

        return;
    }

    star(N/2, r-N/3, c, arr);
    star(N/2, r+N/3/2, c-N/2, arr);
    star(N/2, r+N/3/2, c+N/2, arr);

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 2*N; j++) {
            arr[i][j] = ' ';
        }
    }
    star(N, N/3*2, N, arr);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 2*N; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}