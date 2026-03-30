#include <bits/stdc++.h>

using namespace std;
const int MAX = 512;

void dfs(int idx, int sum, 
    vector<int> &counts,
    const vector<int> &vec, 
    const vector<vector<int>> &dice
) {
    if (idx == vec.size()) {
        counts[sum]++;
        return;
    }
    
    int x = vec[idx];
    const vector<int> &die = dice[x];

    for (int i = 0; i < 6; i++) {
        int num = die[i];
        dfs(idx + 1, sum + num, counts, vec, dice);
    }
}

vector<int> solution(vector<vector<int>> dice) {
    int n = dice.size();
    
    int max_wins = 0;
    int optimal_bits = 0;
    
    for (int bits = 0; bits < (1 << n); bits++) {        
        vector<int> a, b;
        for (int idx = 0; idx < n; idx++) {
            bool on = (bits >> idx) & 1;
            if (on) a.push_back(idx);
            else b.push_back(idx);
        }
        
        if (a.size() != b.size()) continue;
        
        vector<int> x(MAX), y(MAX);
        dfs(0, 0, x, a, dice);
        dfs(0, 0, y, b, dice);
        
        int wins = 0;
        for (int i = 0; i < MAX; i++) {
            if (x[i] == 0) continue;
            for (int j = 0; j < i; j++) {
                wins += x[i] * y[j];
            }
        }
        
        if (wins > max_wins) {
            optimal_bits = bits;
            max_wins = wins;
        }
    }
    
    vector<int> ans;
    for (int idx = 0; idx < n; idx++) {
        bool on = (optimal_bits >> idx) & 1;
        if (on) ans.push_back(idx + 1);
    }
    
    return ans;
}
