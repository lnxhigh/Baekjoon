#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> strArr) {
    string target = "ad";
    vector<string> answer;
    
    for (string str : strArr) {
        int pos = str.find(target);
        if (pos != string::npos) continue;
        answer.push_back(str);
    }
    return answer;
}