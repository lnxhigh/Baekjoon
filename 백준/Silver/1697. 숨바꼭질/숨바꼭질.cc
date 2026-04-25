#include <iostream>
#include <queue>
#include <map>
using namespace std;

int N, K;
int X;
queue<int> q;
map<int,bool> visit;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> K;
    if (N >= K) {
        cout << N - K;
        return 0 ;
    }
    
    X = N;
    q.push(X);
    visit[X] = true;
    visit[0] = true;

    int cnt = 0, cur = 1, next = 0;
    int level = 0;

    while(X != K) {
        cnt++;
        X = q.front();
        q.pop();

        if (not visit[2*X]) {
            visit[2*X] = true;
            if (2*X <= K+1) {
                q.push(2*X);
                next++;
            }
        }
        
        if (not visit[X-1]) {
            visit[X-1] = true;
            q.push(X-1);
            next++;
        }
        
        if (not visit[X+1]) {
            visit[X+1] = true;
            q.push(X+1);
            next++;
        }

        if (cnt == cur) {
            cnt = 0;
            cur = next;
            next = 0;
            level++;
        }
    }

    if (not cnt) level--;
    cout << level;

    return 0;
}