#include <iostream>
using namespace std;

int N;
bool paper[128][128];
int white = 0, blue = 0;

void check(int x, int y, int N) {
    if (N == 1) {
        if (paper[x][y]) blue++;
        else white++;
        return;
    }

    bool split = true;
    bool start = paper[x][y];
    for (int i = x; i < x+N; i++) {
        if (not split) break;
        for (int j = y; j < y+N; j++) {
            if (paper[i][j] != start) {
                split = false;
                break;
            }
        }
    }

    if (split) {
        if (start) blue++;
        else white++;
        return;
    }
    else {
        check(x, y, N/2);
        check(x+N/2, y, N/2);
        check(x, y+N/2, N/2);
        check(x+N/2, y+N/2, N/2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    check(0, 0, N);
    cout << white << '\n';
    cout << blue << '\n';

    return 0;
}