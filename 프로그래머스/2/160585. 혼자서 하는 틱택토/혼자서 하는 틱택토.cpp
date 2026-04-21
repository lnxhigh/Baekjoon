#include <bits/stdc++.h>
using namespace std;
const int n = 9;

vector<tuple<int,int,int>> lines = {
    {0,1,2},{3,4,5},{6,7,8}, // H
    {0,3,6},{1,4,7},{2,5,8}, // V
    {0,4,8},{2,4,6} // D
};

bool check(const string &str) {
    for (auto [i, j, k] : lines) {
        char x = str[i], y = str[j], z = str[k];
        if (x == '.' or y == '.' or z == '.') continue;
        else if (x == y and y == z and z == x) return true;
    }
    return false;
}

int solution(vector<string> board) {
    vector<int> first, second;
    string str = board[0] + board[1] + board[2];
    
    for (int i = 0; i < n; i++) {
        char x = str[i];
        if (x == 'O') first.push_back(i);
        else if (x == 'X') second.push_back(i);
    }
    
    int cnt = first.size() - second.size();
    if (cnt != 0 and cnt != 1) return false;
    
    if (first.empty() or second.empty()) return true;
    
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    
    do {
        do {
            string now = ".........";
            
            for (int i = 0; i < n; i++) {
                vector<int> &vec = (i % 2 == 0) ? first : second;
                if (i / 2 >= vec.size()) break;
                
                int idx = vec[i / 2];
                now[idx] = (i % 2 == 0) ? 'O' : 'X';
                
                if (now == str) return true;
                if (check(now)) break;
            }
            
            if (now == str) return true;
        } while (next_permutation(second.begin(), second.end()));
    } while (next_permutation(first.begin(), first.end()));
    
    return false;
}
