#include <bits/stdc++.h>
using namespace std;

int f(int x) {
    if (x == 0) return 0;
    
    int i = 1;
    while (i * 10 <= x) i *= 10;
    
    int t = x / i;
    if (i * t == x) return min(t, 11 - t);
    
    int a = f(x - i * t) + min(t, 11 - t);
    int b = f(i * (t + 1) - x) + min(t + 1, 10 - t);
    
    return min(a, b);
}

int solution(int x) {
    return f(x);
}
