#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    const int N = a.size();
    
    int answer = 0;
    for (int i = 0; i < N; i++) {
        answer += a[i] * b[i];
    }
    return answer;
}