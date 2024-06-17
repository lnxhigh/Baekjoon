#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using Point = pair<int,int>;

int N, K, H, M;
const int N_MAX = 1000;
const int K_MAX = 5;
const int H_MAX = 50;
const int M_MAX = K_MAX * H_MAX;
const int MAX = M_MAX + H_MAX + 2;
const int INF = 1 << 20;

Point Corner[N_MAX];
Point Hole[H_MAX];
Point Mouse[M_MAX];

vector<int> graph[MAX];
const int S = M_MAX + H_MAX;
const int T = S + 1;

int capacity[MAX][MAX];
int flow[MAX][MAX];

int ccw(const Point &A, const Point &B, const Point &C) {
    int x1 = B.X - A.X, y1 = B.Y - A.Y;
    int x2 = C.X - A.X, y2 = C.Y - A.Y;
    long long det = 1LL * x1 * y2 - 1LL * y1 * x2;
    if (det > 0) return 1;
    else if (det < 0) return -1;
    return 0;
}

void swap(Point &A, Point &B) {
    Point tmp = A;
    A = B;
    B = tmp;
}

bool isIntersect(Point A, Point B, Point C, Point D) {
    int x = ccw(A, B, C) * ccw(A, B, D);
    int y = ccw(C, D, A) * ccw(C, D, B);
    
    if (x == 0 && y == 0) {
        if (A > B) swap(A, B);
        if (C > D) swap(C, D);
        return A <= D && B >= C;        
    }

    return x <= 0 && y <= 0;
}

bool canEnter(const Point &mousePos, const Point &holePos) {
    for (int i = 0; i < N; i++) {
        int cur = i % N, next = (i + 1) % N;
        
        // 현재 구멍이 존재하는 벽과는 교차 검사를 하지 않도록 만든다
        if (holePos.X == Corner[cur].X && holePos.X == Corner[next].X) continue;
        if (holePos.Y == Corner[cur].Y && holePos.Y == Corner[next].Y) continue;

        // 이외의 벽과 교차가 일어나면 쥐는 구멍을 찾을 수 없으므로 진입 불가능하다
        if (isIntersect(mousePos, holePos, Corner[cur], Corner[next])) {
            return false;
        }
    }

    return true;
}

int maxFlow(int source, int sink) {
    int res = 0;
    
    while (true) {
        queue<int> q;
        q.push(source);
        int P[MAX];

        // 증가 경로 추적
        fill(P, P + MAX, -1);
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int next : graph[cur]) {
                // 흘려 줄 유량이 존재하고 아직 방문하지 않았으면 큐에 넣는다
                if (capacity[cur][next] > flow[cur][next] && P[next] == -1) {
                    q.push(next);
                    P[next] = cur;

                    // 증가 경로가 존재하면 BFS 탈출
                    if (next == sink) break;
                }
            }
        }

        // 증가 경로가 없으면 최상단 반복문 탈출
        if (P[sink] == -1) break;
        
        // 증가 경로가 존재하면 경로 상의 최대 유량을 구한다
        int amount = INF;
        for (int i = sink; i != source; i = P[i]) {
            int spare = capacity[P[i]][i] - flow[P[i]][i];
            amount = min(amount, spare);
        }

        // 경로 상의 모든 지점에 대해 유량을 흘려 준다
        for (int i = sink; i != source; i = P[i]) {
            flow[P[i]][i] += amount;
            flow[i][P[i]] -= amount;
        }

        // 결과 업데이트    
        res += amount;
    }

    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력 처리
    cin >> N >> K >> H >> M;

    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        Corner[i] = { x, y };
    }
    for (int i = 0; i < H; i++) {
        cin >> x >> y;
        Hole[i] = { x, y };
    }
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        Mouse[i] = { x, y };
    }

    // 그래프 빌드
    
    // S -> Mouse 연결
    for (int i = 0; i < M; i++) {
        graph[S].push_back(i);
        graph[i].push_back(i);
        capacity[S][i] = 1;
    }

    // Mouse -> Hole 연결
    for (int m = 0; m < M; m++) {
        for (int h = 0; h < H; h++) {
            if (canEnter(Mouse[m], Hole[h])) {
                int newH = h + M_MAX;
                graph[m].push_back(newH);
                graph[newH].push_back(m);
                capacity[m][newH] = 1;
            }
        }
    }

    // Hole -> T 연결
    for (int i = M_MAX; i < M_MAX + H; i++) {
        graph[i].push_back(T);
        graph[T].push_back(i);
        capacity[i][T] = K;
    }

    // 네트워크 최대 유량 및 결과 출력
    // 그래프 빌드 시 시간복잡도 - O( N*M*H )
    // 최대 유량 시간복잡도 - O(V*E^2) => O( (M+H)*(M*H)^2 )
    int cnt = maxFlow(S, T);
    string answer = (cnt >= M) ? "Possible" : "Impossible";
    cout << answer << '\n';

    return 0;    
}
