#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, string delimiter) {
    int pos;
    string token;
    vector<string> res;
    
    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        res.push_back(token);
        input.erase(0, pos + delimiter.size());
    }
    res.push_back(input);
    
    return res;
}

vector<int> solution(string myString) {
    string delimiter = "x";
    vector<string> tokens = split(myString, delimiter);
    
    vector<int> answer(tokens.size());
    transform(tokens.begin(), tokens.end(), answer.begin(), [] (string str) {
       return str.size();
    });
    
    return answer;
}