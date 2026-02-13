#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
vector<char> ops;
int m[128][128][2];
bool chk[128][128][2];

int solve(int from, int to, int maximize) {
    if (chk[from][to][maximize]) {
        return m[from][to][maximize];
    }
    if (from == to) {
        return nums[from];
    }
    
    int res = maximize ? -100000000 : 100000000;
    
    if (maximize) {
        for (int i = from; i < to; i++) {
            char op = ops[i];
            if (op == '+') {
                res = max(res, solve(from, i, 1) + solve(i + 1, to, 1));
            } else if (op == '-') {
                res = max(res, solve(from, i, 1) - solve(i + 1, to, 0));
            }
        }
    } else {
        for (int i = from; i < to; i++) {
            char op = ops[i];
            if (op == '+') {
                res = min(res, solve(from, i, 0) + solve(i + 1, to, 0));
            } else if (op == '-') {
                res = min(res, solve(from, i, 0) - solve(i + 1, to, 1));
            }
        }
    }
    
    chk[from][to][maximize] = true;
    return m[from][to][maximize] = res;
}

int solution(vector<string> arr)
{
    for (int i = 0; i < arr.size(); i++) {
        if (i & 1) {
            char op = arr[i][0];
            ops.push_back(op);
        } else {
            int num = stoi(arr[i]);
            nums.push_back(num);   
        }
    }
    
    int n = nums.size();
    int ans = solve(0, n - 1, 1);
    return ans;
}
