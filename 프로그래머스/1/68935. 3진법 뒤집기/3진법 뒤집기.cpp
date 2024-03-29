#include <bits/stdc++.h>

using namespace std;

string ternary(int N) {
    if (N < 3) return to_string(N);
    return ternary(N / 3) + to_string(N % 3);
}

int solution(int N) {
    int answer = 0;
    string tri = ternary(N);
    
    int mul = 1;
    for (char c : tri) {
        int x = c - '0';
        answer += x * mul;
        mul *= 3;
    }
    
    return answer;
}