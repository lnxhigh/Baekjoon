#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    
    if (k % 2 == 1) { for (int i : arr) answer.push_back(i * k); }
    else { for (int i : arr) answer.push_back(i + k); }
    
    return answer;
}