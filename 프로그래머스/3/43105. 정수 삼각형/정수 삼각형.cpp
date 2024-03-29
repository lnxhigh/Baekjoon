#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define N_MAX 501

using namespace std;

int dp[N_MAX][N_MAX];
int solution(vector<vector<int>> triangle) {
    const int H = triangle.size();
    
    // Initialize
    dp[0][0] = triangle[0][0];
    
    // Edge
    for (int h = 1; h < H; h++) {
        dp[h][0] = dp[h-1][0] + triangle[h][0];
        dp[h][h] = dp[h-1][h-1] + triangle[h][h];
    }
    
    // Middle
    for (int h = 1; h < H; h++) {
        for (int i = 1; i < h; i++) {
            int left = dp[h-1][i-1];
            int right = dp[h-1][i];
            
            dp[h][i] = max(left, right) + triangle[h][i];
        }
    }

    int answer;
    answer = *max_element(dp[H-1], dp[H-1] + H);

    return answer;
}