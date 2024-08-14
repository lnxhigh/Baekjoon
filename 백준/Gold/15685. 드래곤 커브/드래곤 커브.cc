#include <bits/stdc++.h>
using namespace std;

int N;
int x, y, dir, gen;
const int MAX = 101;
bool dragon[MAX][MAX];

// right up left down
int dx[4] = { 0, -1, 0, +1 };
int dy[4] = { +1, 0, -1, 0 };

int countSquares() {
    int res = 0;
    int x[4] = { 0, 0, 1, 1 };
    int y[4] = { 0, 1, 0, 1 };

    for (int i = 0; i < MAX-1; i++) {
        for (int j = 0; j < MAX-1; j++) {
            bool check = true;
            for (int k = 0; k < 4; k++) {
                if (!dragon[i+x[k]][j+y[k]]) {
                    check = false;
                    break;
                }
            }

            if (check) res++;
        }
    }

    return res;
}

void draw(int x, int y, int dir, int gen) {
    vector<pair<int,int>> path; // points
    path.reserve(1 << (gen + 1));
    
    int px = x + dx[dir], py = y + dy[dir]; // pivot

    // init
    dragon[x][y] = dragon[px][py] = true;
    path.push_back({ x, y });
    path.push_back({ px, py });

    for (int g = 0; g < gen; g++) {
        // draw
        for (auto point : path) {
            int nx = point.first, ny = point.second; // next
            int rx = (ny - py) + px, ry = -(nx - px) + py; // rotate
            dragon[rx][ry] = true;
            path.push_back({ rx, ry });
        }

        // get next pivot
        int npx =  (y - py) + px;
        int npy = -(x - px) + py;
        px = npx, py = npy;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    while (N--) {
        cin >> x >> y >> dir >> gen;
        draw(y, x, dir, gen);
    }
    
    int res = countSquares();
    cout << res << '\n';
    return 0;
}
