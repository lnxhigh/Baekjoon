#include <bits/stdc++.h>
using namespace std;

int f(int m, int n, int a, int b, int x, int y) {
    int value = 1 << 30;
    int first[4] = { x, x, -x, 2 * m - x };
    int second[4] = { -y, 2 * n - y, y, y };
    
    // 상 하 좌 우
    for (int i = 0; i < 4; i++) {
        if (a == x && b > y && i == 0) continue;
        if (a == x && b < y && i == 1) continue;
        if (b == y && a > x && i == 2) continue;
        if (b == y && a < x && i == 3) continue;
        
        int dx = first[i] - a;
        int dy = second[i] - b;
        int r2 = dx * dx + dy * dy; 
        value = min(value, r2);
    }
    
    return value;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> ans;
    for (const vector<int> &ball : balls) {
        int x = ball[0], y = ball[1];
        int value = f(m, n, startX, startY, x, y);
        ans.push_back(value);
    }
    
    return ans;
}