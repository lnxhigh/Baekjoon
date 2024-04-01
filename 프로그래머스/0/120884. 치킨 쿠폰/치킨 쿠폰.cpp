#include <bits/stdc++.h>
using namespace std;

int solution(int chicken) {
    int answer = 0;
    int coupon = 0;
    
    while (true) {
        coupon += chicken;
        chicken = 0;
        if (coupon < 10) break;
        
        chicken += coupon / 10;
        answer += coupon / 10;
        coupon %= 10;
    }
    
    return answer;
}