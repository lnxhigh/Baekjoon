#include <bits/stdc++.h>
using namespace std;
const int MAX = 1 << 10;

long long solution(vector<int> weights) {
    long long ans = 0;
    vector<long long> arr(MAX);
    for (int x : weights) arr[x]++;
    
    long long a = 0;
    long long b = 0;
    
    for (int i = 1; i < MAX; i++) {
        if (arr[i] == 0) continue;
        a += arr[i] * (arr[i] - 1) / 2;
    }
    
    for (int i = 1; i < MAX; i++) {
        for (int j = i + 1; j < MAX; j++) {
            if (i == j) continue;
            if (arr[i] == 0 or arr[j] == 0) continue;
            
            bool flag = false;
            for (int x = 2; x <= 4; x++) {
                for (int y = 2; y <= 4; y++) {
                    if (i * x != j * y) continue;
                    flag = true;
                }
            }
            
            if (flag) b += arr[i] * arr[j];
        }
    }
    
    return a + b;
}
