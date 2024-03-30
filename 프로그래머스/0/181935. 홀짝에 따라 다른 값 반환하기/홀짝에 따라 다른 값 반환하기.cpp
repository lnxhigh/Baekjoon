#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    return n&1 ? (n+1)*(n+1)/4 : n*(n/2+1)*(n+1)/3;
}