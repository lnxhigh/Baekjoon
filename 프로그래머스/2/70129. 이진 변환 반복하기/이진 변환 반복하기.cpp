#include <bits/stdc++.h>

using namespace std;

string binary(int n) {
    if (n < 2) return to_string(n);
    return binary(n / 2) + to_string(n % 2);
}

vector<int> solution(string s) {
    int cnt = 0;
    int zero = 0;
    
    while (s != "1") {
        const int N = s.size();
        const int one = count(s.begin(), s.end(), '1');
        cnt++;
        zero += N - one;
        
        s = binary(one);
    }
    
    vector<int> answer = { cnt, zero };
    return answer;
}