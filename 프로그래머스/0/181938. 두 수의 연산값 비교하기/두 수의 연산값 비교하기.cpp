#include <bits/stdc++.h>
using namespace std;

int add(int a, int b) {
    string x = to_string(a);
    string y = to_string(b);
    return stoi(x + y);
}

int solution(int a, int b) {
    int answer;
    int x = add(a, b);
    int y = 2 * a * b;
    
    if (x > y) answer = x;
    else if (x < y) answer = y;
    else answer = add(x, y);
    
    return answer;
}