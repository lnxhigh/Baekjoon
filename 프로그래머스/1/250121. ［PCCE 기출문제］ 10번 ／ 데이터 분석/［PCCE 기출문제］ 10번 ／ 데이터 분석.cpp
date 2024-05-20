#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    unordered_map<string,int> info;
    int index;
    
    // ["코드 번호(code)", "제조일(date)", "최대 수량(maximum)", "현재 수량(remain)"]
    vector<string> strs = { "code", "date", "maximum", "remain" };
    for (int i = 0; i < 4; i++) {
        info[strs[i]] = i;
    }
        
    // data에서 ext 값이 val_ext보다 작은 데이터만 뽑기
    index = info[ext];
    for (vector<int> datum : data) {
        if (datum[index] < val_ext) {
            answer.push_back(datum);
        }
    }
    
    // sort_by에 해당하는 값을 기준으로 오름차순으로 정렬
    index = info[sort_by];
    sort(answer.begin(), answer.end(), [&index] (vector<int> &left, vector<int> &right) {
        return left[index] < right[index];
    });
    
    return answer;
    
}