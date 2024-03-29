// 전체 최단거리를 구한다
// N = 200 이므로 OK
// 모든 노드에 대해 지점 k까지 합승했을 때의 비용을 구한다
// 지점 k서붜 각각의 목적지까지 가는 데 비용을 더해서 최종 비용을 산출한다

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define N_MAX 201
#define INF 100000000

using namespace std;

int graph[N_MAX][N_MAX] = {0,};
int dist[N_MAX][N_MAX] = {0,};
int costs[N_MAX] = {0,};

void Floyd(int graph[N_MAX][N_MAX], int N) {
    // Initialize
    for (int from = 1; from <= N; from++) {
        for (int to = 1; to <= N; to++) {
            if (from == to) dist[from][to] = 0;
            else if (graph[from][to]) dist[from][to] = graph[from][to];
            else dist[from][to] = INF;
        }
    }
    
    // Update
    for (int k = 1; k <= N; k++) {
        for (int from = 1; from <= N; from++) {
            for (int to = 1; to <= N; to++) {
                dist[from][to] = min(dist[from][to], dist[from][k] + dist[k][to]);
            }
        }
    }
    
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for (vector<int> fare : fares) {
        int from, to, cost;
        from = fare[0];
        to = fare[1];
        cost = fare[2];
        graph[from][to] = cost;
        graph[to][from] = cost;
    }
    
    Floyd(graph, n);
    for (int k = 1; k <= n; k++) {
        costs[k] = dist[s][k] + dist[k][a] + dist[k][b];
    }
    
    int answer = *min_element(costs + 1, costs + 1 + n);
    return answer;
}