#include <bits/stdc++.h>

using namespace std;
const int MAX = 10001;

map<string, int> names;
int par[MAX], sum[MAX];

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    int n = enroll.size();
    names["-"] = 0, par[0] = -1;
    
    for (int i = 0; i < n; i++) {
        names[enroll[i]] = i + 1;
        par[i + 1] = names[referral[i]];
    }
    
    int k = seller.size();
    for (int i = 0; i < k; i++) {
        int x = names[seller[i]];
        int profit = amount[i] * 100;
            
        while (profit > 0) {
            sum[x] += profit;
            
            int p = par[x];
            if (p < 0) break;
            
            int m = profit / 10;
            sum[x] -= m;
            
            x = p;
            profit = m;
        }
    }
    
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int idx = names[enroll[i]];
        ans.push_back(sum[idx]);
    }
    
    return ans;
}
