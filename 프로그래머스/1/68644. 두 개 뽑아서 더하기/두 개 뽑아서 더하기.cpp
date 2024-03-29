#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> numbers) {
    const int N = numbers.size();
    set<int> result;

    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int sum = numbers[i] + numbers[j];
            result.insert(sum);
        }
    }
    
    vector<int> answer;
    for (auto iter = result.begin(); iter != result.end(); ++iter) {
        answer.push_back(*iter);
    }
    
    return answer;
}