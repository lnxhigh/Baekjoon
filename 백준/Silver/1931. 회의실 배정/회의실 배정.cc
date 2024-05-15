#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
using deadline = pair<int,int>;

int N;
int start, end_;
deadline meeting[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> start >> end_;
        meeting[i] = { start, end_ }; 
    }
    
    sort(meeting, meeting + N, [](deadline x, deadline y) { 
        if (x.second < y.second) return true;
        else if (x.second > y.second) return false;
        else {
            if (x.first < y.first) return true;
            else return false;
        }
    });
    
    int cnt = 0;
    
    start = 0; end_ = 0;
    for (int i = 0; i < N; i++) {
        deadline m = meeting[i];
        if (m.first >= end_) {
            cnt++;
            end_ = m.second;
        }
    }
    cout << cnt;

    return 0;
}
