#include <bits/stdc++.h>
using namespace std;

int dfs(int x, int p) {
    int m = log(x) / log(3);
    if (m * 2 < p) return 0;
        
    if (x <= 0) return 0;
    else if (x == 1) return p == 0;
    
    int sum = dfs(x - 1, p + 1);
    bool match = (x % 3 == 0) && (p > 1);
    if (match) sum += dfs(x / 3, p - 2);
    
    return sum;
}

int solution(int n) {
    return dfs(n, 0);
}
