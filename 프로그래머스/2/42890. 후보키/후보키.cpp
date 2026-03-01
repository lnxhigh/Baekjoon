#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> relation) {
    int nrow = relation.size();
    int ncol = relation[0].size();
    
    int ans = 0;
    set<int> all;
    vector<int> keys;
    
    // Uniqueness
    
    for (int bits = 0; bits < (1 << ncol); bits++) {
        set<vector<string>> check;
        bool flag = true;
        
        for (const vector<string> &entity : relation) {
            vector<string> vec;
            for (int i = 0; i < ncol; i++) {
                if ((bits >> i & 1) == 0) continue;
                string value = entity[i];
                vec.push_back(value);
            }
            
            if (check.count(vec)) flag = false;
            if (!flag) break;
            check.insert(vec);
        }
        
        if (flag) {
            all.insert(bits);
            keys.push_back(bits);
        }
    }
    
    // Minimality
    
    for (int key : keys) {
        bool flag = true;
        for (int i = 0; i < ncol && flag; i++) {
            if ((key >> i & 1) == 0) continue;
            
            int t = key & ~(1 << i);
            if (all.count(t)) flag = false;
        }
        
        if (flag) ans++;
    }
    
    return ans;
}
