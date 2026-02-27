#include <string>
#include <vector>

using namespace std;

// 최고의 집합을 리턴

vector<int> solution(int n, int s) {
    if (n > s) return { -1 };
    
    vector<int> ans;
    
    int q = s / n, r = s % n;
    for (int i = 0; i < n - r; i++) ans.push_back(q);
    for (int i = 0; i < r; i++) ans.push_back(q + 1);
    
    return ans;
}
