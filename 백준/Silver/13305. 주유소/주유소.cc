#include <iostream>
#include <queue>
#define MAX 100000
#define ll long long
using namespace std;

ll N;
ll dist[MAX];
ll cost[MAX];
ll cheapest = 1 << 30;
ll betweenDist = 0;
queue<int> visit;
queue<ll> fuel;

int main(void) {
    cin >> N;

    dist[0] = 0;
    for (int i = 1; i < N; i++) { cin >> dist[i]; }
    for (int i = 0; i < N; i++) { cin >> cost[i]; }
    cost[N-1] = -(1 << 30);

    for (int i = 0; i < N; i++) {
        betweenDist += dist[i];
        if (cost[i] < cheapest) {
            cheapest = cost[i];
            visit.push(i);
            fuel.push(betweenDist);
            betweenDist = 0;
        }
    }

    fuel.pop();
    int K = fuel.size();
    ll answer = 0;

    for (int i = 0; i < K; i++) {
        answer += cost[visit.front()] * fuel.front();
        visit.pop(); fuel.pop();
    }
    cout << answer;
}