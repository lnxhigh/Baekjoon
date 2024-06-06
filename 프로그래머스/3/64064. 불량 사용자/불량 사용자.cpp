#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> users;
unordered_map<string,int> idToNum;
unordered_set<int> s;

bool check(string &userId, string &bannedId) {
    if (userId.size() != bannedId.size()) return false;
    for (int i = 0; i < userId.size(); i++) {
        if (bannedId[i] != '*' && userId[i] != bannedId[i]) return false;
    }
    return true;
}

bool checkAll(vector<string> &users, vector<string> &banned_id) {
    for (int i = 0; i < M; i++) {
        if (!check(users[i], banned_id[i])) {
            return false;
        }
    }
    return true;
}

void dfs(int depth, vector<string> &user_id, vector<string> &banned_id) {
    if (users.size() == M) {
        if (checkAll(users, banned_id)) {
            int x = 0;
            for (string user : users) {
                x += (1 << idToNum[user]);
            }
            s.insert(x);
        }
        return;
    }
    
    for (string user : user_id) {
        // continue if user is in users
        if (find(users.begin(), users.end(), user) != users.end()) continue;
        
        users.push_back(user);
        dfs(depth+1, user_id, banned_id);
        users.pop_back();
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    N = user_id.size();
    M = banned_id.size();
    
    for (int i = 0; i < user_id.size(); i++) {
        idToNum[user_id[i]] = i;
    }
    dfs(0, user_id, banned_id);
    
    int answer = s.size();
    return answer;
}