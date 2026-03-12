#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<string> data) {
    int ans = 0;
    string friends = "ACFJMNRT";
    int index[128] = { 0 };
    
    vector<int> order;
    vector<int> location(friends.size());
    
    for (int i = 0; i < friends.size(); i++) {
        index[friends[i]] = i;
        order.push_back(i);
    }
    
    do {
        for (int i = 0; i < order.size(); i++) {
            location[order[i]] = i;
        }
        
        bool flag = true;
        
        for (const string &str : data) {
            char src = str[0];
            char dst = str[2];
            char op = str[3];
            int x = str[4] - '0';
            
            int dist = abs(location[index[src]] - location[index[dst]]) - 1;
            
            bool chk = false;
            if (op == '>') chk = (dist > x);
            else if (op == '<') chk = (dist < x);
            else chk = (dist == x);
            
            if (!chk) flag = false;
            if (!flag) break;
        }
        
        if (flag) ans++;
    } while (next_permutation(order.begin(), order.end()));
    
    return ans;
}
