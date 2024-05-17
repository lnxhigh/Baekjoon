#include <bits/stdc++.h>
using namespace std;

int N;
char video[64][64];

bool check(int x, int y, int N) {
    // check if video consists of one number
    char first = video[x][y];

    for (int i = x; i < x + N; i++) {
        for (int j = y; j < y + N; j++) {
            if (first != video[i][j]) {
                return false;
            }
        }
    }

    return true;
}

string compress(int x, int y, int N) {

    if (check(x, y, N)) {
        string s = "";
        s += video[x][y];
        return s;
    }
    
    else {
        string s = "";
        int M = N >> 1;
        pair<int,int> starts[4] = { {x,y}, {x,y+M}, {x+M,y}, {x+M,y+M} };

        s += "(";
        for (pair<int,int> start : starts) {
            s += compress(start.first, start.second, M);
        }
        s += ")";

        return s;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> video[i][j];
        }
    }

    cout << compress(0, 0, N) << '\n';
    
    return 0;
}
