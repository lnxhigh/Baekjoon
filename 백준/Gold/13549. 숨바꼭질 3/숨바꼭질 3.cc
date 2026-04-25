#include <iostream>
#include <queue>
#include <utility>
using namespace std;
using xy = pair<int,int>;
bool visited[100001] = {false,};

int N, K;
int depth = 0;
queue<xy> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> K;

    if (K == 0) {
        cout << N-K;
        return 0;
    }

    if (N == 0) {
        depth++;
        N++;
    }

    int X = N;
    visited[X] = true;

    q.push({N,depth});

    while (true) {
        X = q.front().first;
        depth = q.front().second;
        q.pop();
        
        if (X == K) {
            cout << depth << '\n';
            break;
        }

        if (X-1 > 0) {
            if (not visited[X-1]) {
                visited[X-1] = true;
                q.push({X-1, depth+1});
            }
        }
        if (2*X <= 100000) {
            if (not visited[2*X]) {
                visited[2*X] = true;
                q.push({2*X, depth});
            }
        }
        if (X+1 <= 100000) {
            if (not visited[X+1]) {
                visited[X+1] = true;
                q.push({X+1, depth+1});
            }
        }
    }

    return 0;
}