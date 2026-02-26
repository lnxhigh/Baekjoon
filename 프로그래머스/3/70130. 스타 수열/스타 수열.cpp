#include <bits/stdc++.h>

using namespace std;

const int MAX = 500005;
vector<int> pos[MAX];

int solution(vector<int> nums) {
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        pos[x].push_back(i);
    }
    
    int ans = 0;
    
    for (int i = 0; i < MAX; i++) {
        if (pos[i].empty()) continue;
        
        vector<int> &vec = pos[i];
        sort(vec.begin(), vec.end());
        
        int cnt = 0;
        int s = vec.size();
        
        int m = -1;
        
        for (int j = 0; j < s; j++) {
            // Left match
            if (j > 0) {
                bool match = (vec[j] - vec[j - 1] > 2)
                    || (vec[j] - vec[j - 1] == 2 && vec[j] - 1 != m);
                
                if (match) {
                    cnt++;
                    m = vec[j] - 1;
                    continue;
                }
            } else if (j == 0) {
                bool match = vec[j] > 0;
                
                if (match) {
                    cnt++;
                    m = vec[j] - 1;
                    continue;   
                }                
            }
            
            // Right match
            if (j < s - 1) {
                bool match = (vec[j + 1] - vec[j] > 1);
                if (match) {
                    cnt++;
                    m = vec[j] + 1;
                    continue;
                }
            } else if (j == s - 1) {
                bool match = vec[j] < (n - 1);
                if (match) {
                    cnt++;
                    m = vec[j] + 1;
                    continue;   
                }   
            }
        }

        ans = max(ans, cnt << 1);
    }
    
    return ans;
}
