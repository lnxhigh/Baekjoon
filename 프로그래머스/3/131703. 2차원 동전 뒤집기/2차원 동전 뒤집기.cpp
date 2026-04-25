#include <string>
#include <vector>

using namespace std;

int f(int x, int y,
    const vector<vector<int>> from, const vector<vector<int>> to
) {
    int cnt = 0;
    int h = from.size();
    int w = from[0].size();
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            bool now = from[i][j];
            bool target = to[i][j];
    
            if (x >> i & 1) now ^= true;
            if (y >> j & 1) now ^= true;
            if (now ^ target) return -1;
        }
    }
    
    for (int i = 0; i < h; i++) {
        if (x >> i & 1) cnt++;
    }
    for (int i = 0; i < w; i++) {
        if (y >> i & 1) cnt++;
    }
    
    return cnt;
}

int solution(vector<vector<int>> from, vector<vector<int>> to) {
    int ans = -1;
    int h = from.size();
    int w = from[0].size();
    
    for (int x = 0; x < (1 << h); x++) {
        for (int y = 0; y < (1 << w); y++) {
            int cnt = f(x, y, from, to);
            if (cnt < 0) continue;
            ans = (ans < 0) ? cnt : min(ans, cnt);
        }
    }
    
    return ans;
}