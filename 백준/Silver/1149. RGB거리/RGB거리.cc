#include <iostream>
#define INF 2147483647
#define MAX 1000
using namespace std;

int N;
int r, g, b;
int answer = INF;
int arr[MAX+1][3] = {0,};
int cost[MAX+1][3] = {0,};
int Min (int x, int y) { return x < y ? x : y ; }
enum { R, G, B, K };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> r >> g >> b;
        arr[i][R] = r; arr[i][G] = g; arr[i][B] = b;
    }   
    
    cost[1][R] = arr[1][R]; cost[1][G] = arr[1][G]; cost[1][B] = arr[1][B];

    for (int i = 2; i <= N; i++) {
        for (int color = 0; color < K; color++) {
            cost[i][color] = Min( cost[i-1][(color+1) % K], cost[i-1][(color+2) % K] ) + arr[i][color];
        }
    }
    
    for (int i = 0; i < 3; i++) {
        answer = Min(answer, cost[N][i]);
    }
    
    cout << answer;

    return 0;
}