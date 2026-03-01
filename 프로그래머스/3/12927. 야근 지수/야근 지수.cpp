#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    priority_queue<int> pq;
    for (int work : works) pq.push(work);
    
    while (n > 0 && !pq.empty()) {
        int work = pq.top();
        pq.pop();
        
        n--, work--;
        if (work > 0) pq.push(work);
    }
    
    long long ans = 0;
    while (!pq.empty()) {
        int work = pq.top();
        pq.pop();
        ans += (long long) work * work;
    }
    
    return ans;
}
