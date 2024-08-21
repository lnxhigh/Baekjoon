#include <bits/stdc++.h>
using namespace std;

// How to optimize ???

int TC;
const int offset = 1 << 14;

int f(int x, int y) {
    x += offset, y += offset; 
    int s = x + y;
    return s*(s+1) / 2 + y;
}

int main() {
    cin >> TC;
    while (TC--) {
        int N;
        vector<pair<int,int>> locs;
        unordered_set<int> squares;
        
        cin >> N;
        for (int i = 0; i < N; i++) {
            int X, Y;
            cin >> X >> Y;
            locs.push_back({ X, Y });
            squares.insert(f(X, Y));
        }

        int res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                int x1 = locs[i].first, y1 = locs[i].second;
                int x2 = locs[j].first, y2 = locs[j].second;

                int dx = x1 - x2, dy = y1 - y2;
                int area = dx*dx + dy*dy;
                if (area <= res) continue;

                vector<pair<int,int>> signs = { {-1,+1}, {+1,-1} };
                for (const pair<int,int> &sign : signs) {
                    int sx = sign.first, sy = sign.second;
                    
                    int x3 = x1 + sx * dy, y3 = y1 + sy * dx;
                    if (squares.find(f(x3, y3)) == squares.end()) continue;
                    int x4 = x2 + sx * dy, y4 = y2 + sy * dx;
                    if (squares.find(f(x4, y4)) == squares.end()) continue;

                    res = area;
                }
            }
        }

        cout << res << '\n';
    }

    return 0;
}
