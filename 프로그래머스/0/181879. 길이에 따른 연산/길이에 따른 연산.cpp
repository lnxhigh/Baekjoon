#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    const int N = num_list.size();
    const auto& s = begin(num_list);
    const auto& e = end(num_list);
    
    if (N > 10) answer = accumulate(s, e, 0);
    else answer = accumulate(s, e, 1, multiplies<int>());
    
    return answer;
}