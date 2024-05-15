#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int empty = n;
    int coke = 0;
    int answer = 0;
    
    while (empty >= a) {
        coke += empty / a * b;
        empty %= a;
        empty += coke;
        
        answer += coke;
        coke = 0;
    }
    
    return answer;
}