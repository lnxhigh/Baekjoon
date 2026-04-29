#include <bits/stdc++.h>
using namespace std;

int solution(int len, int capacity, vector<int> weights) {
    int n = weights.size();
    int t = 0, sum = 0;
    int inIdx = 0, outIdx = 0;
    queue<int> q;
    
    while (inIdx < n or outIdx < n) {
        t++;
        
        int size = q.size();
        
        for (int i = 0; i < size; i++) {
            int x = q.front();
            q.pop();
            q.push(x + 1);
        }
        
        if (!q.empty() and q.front() >= len and outIdx < n) {
            int w = weights[outIdx];
            sum -= w;
            outIdx++;
            q.pop();
        }
        
        if (inIdx < n) {
            int w = weights[inIdx];
            if (sum + w <= capacity) {
                sum += w;
                inIdx++;
                q.push(0);   
            }
        }
    }
    
    return t;
}
