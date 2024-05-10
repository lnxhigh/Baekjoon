#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    for (long long x = -1LL * r2; x <= 1LL * r2; x++)
    {
        long long u = floor(sqrt(1LL*r2*r2 - x*x));
        long long l = ceil(sqrt(1LL*r1*r1 - x*x));;
        if (x >= r1 || x <= -r1) 
        {
            answer += u * 2 + 1;
        }
        else
        {
            answer += (u - l + 1) * 2;
        }
    }
    
    return answer;
}