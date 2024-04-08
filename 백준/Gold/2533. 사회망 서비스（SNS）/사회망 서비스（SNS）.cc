#include <bits/stdc++.h>
#define N_MAX 1000001
using namespace std;

int N;
vector<int> tree[N_MAX];
enum { Early, Lazy };
int dp[N_MAX][2];
int visited[N_MAX] = {0,};

void find(int x){
    visited[x]++;
    dp[x][Early] = 1;

    for(int child : tree[x]) {
        if (visited[child]) continue;
        find(child);
        dp[x][Lazy]  += dp[child][Early];
        dp[x][Early] += min(dp[child][Lazy], dp[child][Early]);
    }
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    
    int u,v;
    for(int i = 0; i < N-1; i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    find(1);
    cout << min(dp[1][Early],dp[1][Lazy]);
}
