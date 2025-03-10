#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    const int Q = q.size();
    
    vector<bool> D(n);
    D[0] = D[1] = D[2] = D[3] = D[4] = true;
    
    do {
        bool chk = true;
        
        for (int i = 0; i < Q && chk; i++) {
            int cnt = 0;
            const vector<int> &query = q[i];
            
            for (int k = 0; k < 5; k++) {
                if (D[query[k] - 1]) cnt++;
            }
            
            if (cnt != ans[i]) chk = false;
        }
        
        if (chk) answer++;
        
    } while (prev_permutation(D.begin(), D.end()));
    
    return answer;    
}