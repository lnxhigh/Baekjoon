#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> s;
    for (string &operation : operations) {
        char op = operation[0];
        int num = stoi(operation.substr(2));
        
        if (op == 'I') s.insert(num);
        else if (op == 'D' && !s.empty()) {
            if (num == 1) { s.erase(*s.rbegin()); }
            else if (num == -1) { s.erase(*s.begin()); }
        }
    }
    
    
    vector<int> answer;
    int minValue = s.empty() ? 0 : *s.begin();
    int maxValue = s.empty() ? 0 : *s.rbegin();
    
    answer.push_back(maxValue);
    answer.push_back(minValue);
    return answer;
}