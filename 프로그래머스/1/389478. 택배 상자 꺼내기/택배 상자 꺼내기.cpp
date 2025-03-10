#include <bits/stdc++.h>
using namespace std;

int D[128][16];

int solution(int n, int w, int num) {
    int answer = 0;
    int x = 1, y = 1;
    int sx = 0, sy = 0;
    
    for (int i = 1; i <= n; i++) {
        D[x][y] = i;
        if (i == num) sx = x, sy = y;
        
        if (x & 1) {
            if (y < w) y++;
            else if (y == w) x++;
        }
        else {
            if (y > 1) y--;
            else if (y == 1) x++;
        }
    }
    
    while (D[sx][sy]) {
        cout << D[sx][sy] << ' ';
        answer++;
        sx++;
    }
    
    return answer;
}