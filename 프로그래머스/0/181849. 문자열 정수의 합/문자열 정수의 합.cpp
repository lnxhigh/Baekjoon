#include <bits/stdc++.h>

using namespace std;

int solution(string num_str) {
    int answer = 0;
    for (char c : num_str) {
        int digit = c - '0';
        answer += digit;
    }
    return answer;
}