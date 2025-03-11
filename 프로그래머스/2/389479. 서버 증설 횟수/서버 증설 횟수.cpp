#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int ans = 0;
    queue<int> servers;
    
    for (int t = 0; t < 24; t++) {
        int size = servers.size();
        while (size--) {
            int x = servers.front();
            if (x > 1) servers.push(x - 1);
            servers.pop();
        }
        
        int player = players[t];
        int cnt = servers.size();
        int add = max(player / m - cnt, 0);
        
        ans += add;
        if (add > 0) cout << t << ' ';
        
        while (add--) servers.push(k);
    }
    
    return ans;
}