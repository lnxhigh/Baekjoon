#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    int n = players.size();
    vector<int> arr(n); // player of rank x
    vector<int> ranks(n); // rank of player x
    unordered_map<string,int> names; //  name -> index
    vector<string> ans;
    
    for (int i = 0; i < n; i++) {
        arr[i] = i;
        ranks[i] = i;
        names[players[i]] = i;
    }
    
    for (const string &calling : callings) {
        int idx = names[calling];
        int x = ranks[idx];
        if (x == 0) continue;
        
        int me = arr[x], other = arr[x - 1];
        arr[x] = other, arr[x - 1] = me;
        ranks[me]--, ranks[other]++;
    }
    
    for (int idx : arr) {
        const string &player = players[idx];
        ans.push_back(player);
    }
    
    return ans;
}