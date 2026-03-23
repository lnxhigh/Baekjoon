#include <bits/stdc++.h>

using namespace std;

pair<vector<int>,int> f(int state, int n, const vector<int> &info) {
    vector<int> vec(11);
    int cnt = n;
    int x = 0, y = 0;
    
    for (int i = 0; i <= 10; i++) {
        bool flag = (state >> i) & 1;
        
        // 과녁 맞히기
        if (flag) {
            int add = min(cnt, info[i] + 1);
            vec[i] += add, cnt -= add;
        }
        
        // 점수 비교
        if (vec[i] == 0 and info[i] == 0) continue;
        
        int &z = (vec[i] > info[i]) ? x : y;
        z += 10 - i;
    }

    return { vec, x - y };
}

bool compare(const vector<int> &one, const vector<int> &other) {
    int n = one.size();
    
    for (int i = n - 1; i >= 0; i--) {
        if (one[i] < other[i]) return true;
        else if (one[i] > other[i]) return false;
        else continue;
    }
    
    return false;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ans = { -1 };
    int maxDiff = 0;
    
    for (int state = 0; state < 2048; state++) {
        auto [vec, diff] = f(state, n, info);
        if (diff <= 0) continue;
        
        bool chk = (diff > maxDiff) or (diff == maxDiff and compare(ans, vec));
        
        maxDiff = max(maxDiff, diff);
        if (chk) ans = vec;
    }

    cout << maxDiff;
    return ans;
}
