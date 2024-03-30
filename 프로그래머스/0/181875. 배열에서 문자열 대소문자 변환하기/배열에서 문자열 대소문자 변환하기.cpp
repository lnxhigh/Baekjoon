#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> strArr) {
    const int N = strArr.size();
    for (int i = 0; i < N; ++i) {
        string& str = strArr[i];
        for_each(str.begin(), str.end(), [i](char &c) {
            if (i & 1) c = toupper(c);
            else c = tolower(c);
        });   
    }
    
    vector<string> answer(strArr.begin(), strArr.end());
    
    return answer;
}