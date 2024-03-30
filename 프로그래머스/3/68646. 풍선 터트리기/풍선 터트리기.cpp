#include <bits/stdc++.h>
#define N_MAX 1000000
using namespace std;

int leftMin[N_MAX];
int rightMin[N_MAX];
set<int> balloon;

int solution(vector<int> a) {
    const int N = a.size();
    leftMin[0]  = a[0];
    rightMin[0] = a[N-1];
    
    for (int i = 1; i < N; i++) {
        leftMin[i]  = min(leftMin[i-1] , a[i]    );
        rightMin[i] = min(rightMin[i-1], a[N-1-i]);
    }
    
    for (int i = 0; i < N; i++) {
        balloon.insert(leftMin[i] );
        balloon.insert(rightMin[i]);
    }
    
    int answer = balloon.size();
    return answer;
}