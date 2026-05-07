#include <bits/stdc++.h>
using namespace std;

unordered_set<int> chk;
vector<int> nums[10];

int solution(int n, int x) {
    for (int i = 1, m = n; i <= 8; i++) {
        if (m == x) return i;
        nums[i].push_back(m);
        chk.insert(m);
        m = m * 10 + n;
    }
    
    for (int cnt = 2; cnt <= 8; cnt++) {
        for (int i = 1; i < cnt; i++) {
            for (int a : nums[i]) {
                for (int b : nums[cnt - i]) {
                    for (int t : { a + b, a - b, a * b, a / b }) {
                        if (t == 0) continue;
                        bool flag = (chk.find(t) != chk.end());
                        if (flag) continue;
                        
                        if (t == x) return cnt;
                        chk.insert(t);
                        nums[cnt].push_back(t);
                    }
                }
            }
        }
    }
    
    return -1;
}
