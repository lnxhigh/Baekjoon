#include <iostream>
#include <utility>
#include <queue>
#include <functional>
using namespace std;

int N, x;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater_equal<pair<int,int>>> pq;
int Abs(int x) { return x > 0 ? x : -x; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x == 0 and pq.empty()) {
            cout << 0 << '\n';
            continue;
        }
        
        if (x == 0) {
            cout << pq.top().second << '\n';
            pq.pop();
        }
        else pq.push({Abs(x), x});
    }
    
    return 0;
}