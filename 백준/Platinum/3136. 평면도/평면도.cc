#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N;
set<pair<int,int>> vmp;
set<tuple<int,int,int,int>> emp;

int V, E, F;
int x = 0, y = 0;
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

int main() {
    FastIO
    cin >> N;
    
    V++;
    vmp.insert({ 0, 0 });

    while (N--) {
        char c; cin >> c;
        int dir = (int) (c - '0');

        for (int i = 0; i < 2; i++) {
            int nx = x + dx[dir], ny = y + dy[dir];
            
            if (!vmp.count({ nx, ny })) {
                V++;
                vmp.insert({ nx, ny });
            }

            if (!emp.count({ x, y, nx, ny })) {
                E++;
                emp.insert({ x, y, nx, ny });
                emp.insert({ nx, ny, x, y });
            }

            x = nx, y = ny;
        }
    }

    F = E - V + 1;
    cout << F << '\n';
    return 0;
}
