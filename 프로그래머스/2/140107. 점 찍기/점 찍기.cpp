#include <bits/stdc++.h>

using namespace std;

long long solution(int k, int d) {
    long long cnt = 0;
    
    for (long long x = 0; x * k <= d; x++) {
        long long add = -1;
        long long low = 0, high = d;
        while (low <= high) {
            long long y = (low + high) / 2;
            bool chk = (y * k <= d) and (x * x + y * y) * k * k <= (long long) d * d;
            if (chk) add = y, low = y + 1;
            else high = y - 1;
        }
        
        if (add != -1) cnt += add + 1;
    }
    
    return cnt;
}