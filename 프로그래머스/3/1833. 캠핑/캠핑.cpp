#include <bits/stdc++.h>

using namespace std;

const int MAX = 5001;
int sum[MAX][MAX];

vector<int> normalize(vector<int> &vec) {
    vector<int> arr(vec.begin(), vec.end());
    
    sort(arr.begin(), arr.end());
    auto iter = unique(arr.begin(), arr.end());
    arr.erase(iter, arr.end());
    
    int n = arr.size();
    map<int,int> mp;
    
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        mp[x] = i;
    }
    
    for (int &x : vec) {
        x = mp[x] + 1;
    }
    
    return vec;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {
    int ans = 0;
    memset(sum, 0, sizeof(sum));
    
    vector<int> xs, ys;
    for (auto vec : data) {
        int a = vec[0], b = vec[1];
        xs.push_back(a), ys.push_back(b);
    }
    
    normalize(xs);
    normalize(ys);
    
    for (int i = 0; i < n; i++) {
        auto &p = data[i];
        int x = xs[i], y = ys[i];
        p[0] = x, p[1] = y;
        sum[x][y]++;
    }
    
    int globalMaxX = *max_element(xs.begin(), xs.end());
    int globalMaxY = *max_element(ys.begin(), ys.end());
    
    // Cumulative sum
    for (int x = 1; x < globalMaxX; x++) {
        for (int y = 1; y < globalMaxY; y++) {
            sum[x][y] += sum[x - 1][y] + sum[x][y - 1] - sum[x - 1][y - 1];
        }
    }
    
    // Compute answer
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto &p1 = data[i];
            auto &p2 = data[j];
            
            int minX = min(p1[0], p2[0]);
            int maxX = max(p1[0], p2[0]);
            int minY = min(p1[1], p2[1]);
            int maxY = max(p1[1], p2[1]);
            
            if (minX >= maxX || minY >= maxY) continue;
            
            if (minX + 1 == maxX || minY + 1 == maxY) {
                ans++;
                continue;
            }
            
            int cnt = sum[maxX - 1][maxY - 1];
            cnt -= sum[maxX - 1][minY] + sum[minX][maxY - 1] - sum[minX][minY];
            
            if (cnt == 0) ans++;
        }
    }
    
    return ans;
}
    