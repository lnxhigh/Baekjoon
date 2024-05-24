#include <bits/stdc++.h>
#define N_MAX 1000001
using namespace std;

int N;
int res[N_MAX] = {0,}; // Find Minimum Count
int pre[N_MAX] = {0,}; // Find Path
queue<int> q;
bool visited[N_MAX] = {false,};

int main() {
    cin >> N;
    q.push(1);
    visited[1] = true;
    
    while (!q.empty()) {
        int X = q.front();
        q.pop();
        for (int next : { 3*X, 2*X, X+1 }) {
            if (next > N) continue;
            if (visited[next]) continue;
            q.push(next);
            visited[next] = true;
            
            res[next] = res[X] + 1;
            pre[next] = X;
        }
    }

    cout << res[N] << endl;
    
    for (int i = N; i != 0; i = pre[i]) {
        cout << i << " ";
    }
    
    return 0;
}
