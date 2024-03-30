#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    const int N = num_list.size();
    vector<int> answer;
    
    for (int i = 0; i < N; i += n) {
        answer.push_back(num_list[i]);
    }
    return answer;
}