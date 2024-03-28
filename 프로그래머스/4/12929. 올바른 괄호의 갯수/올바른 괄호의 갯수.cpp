#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> bits;
int answer = 0;

void f(int n) {
    n = n << 1;
    for (int bit = 0; bit < (1 << n); bit++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) cnt++;
        }
        if (cnt != n/2) continue;
        
        bits.push_back(bit);
    }
}

bool check(int bit, int n) {
    stack<int> s;
    
    n = n << 1;
    for (int i = 0; i < n; i++) {
        int k = bit & (1 << i);
        if (k) s.push(k);
        else {
            if (s.empty()) return false;
            else s.pop();
        }
    }
    
    if (not s.empty()) return false;
    return true;

}

int solution(int n) {
    int answer = 0;
    
    f(n);
    for (int bit : bits) {
        if (check(bit, n)) answer++;
    }
    
    return answer;
}