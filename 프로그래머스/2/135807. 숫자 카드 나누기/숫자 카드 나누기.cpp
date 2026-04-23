#include <bits/stdc++.h>
using namespace std;

int gcd(const vector<int> nums) {
    int n = nums.size();
    int x = *nums.begin();
    
    for (int i : nums) x = gcd(x, i);
    return x;
}

bool check(int x, const vector<int> &V) {
    for (int i : V) {
        if (i % x == 0) {
            return false;
        }
    }
    return true;
}

int solve(const vector<int> &A, const vector<int> &B) {
    int x = gcd(A);
    vector<int> divs;
    
    for (int i = 1; i * i <= x; i++) {
        if (x % i != 0) continue;
        divs.push_back(i);
        
        if (x / i == i) continue;
        divs.push_back(x / i);
    }
    
    sort(divs.rbegin(), divs.rend());
    
    for (int i : divs) {
        if (check(i, B)) {
            return i;
        }
    }
    
    return 0;
}

int solution(vector<int> A, vector<int> B) {
    int x = solve(A, B);
    int y = solve(B, A);
    return max(x, y);
}
