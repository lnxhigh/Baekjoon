#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer;
    int N = num_list.size();
    for (int i = n-1; i < N; i++) {
        answer.push_back(num_list[i]);
    }
    return answer;
}