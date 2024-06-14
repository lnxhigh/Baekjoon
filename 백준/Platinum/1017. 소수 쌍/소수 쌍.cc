#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 50;
int A[N_MAX], B[N_MAX];

vector<int> X, Y;

int Nums[N_MAX];

vector<int> graph[N_MAX];
bool visited[N_MAX];

const int P_MAX = 50001;
bool isPrime[P_MAX];

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> Nums[i];
    }
}

void sieve() {
    fill(isPrime, isPrime + P_MAX, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 0; i < P_MAX; i++) {
        if (!isPrime[i]) continue;
        for (int k = i + i; k < P_MAX; k = k + i) {
            isPrime[k] = false;
        }
    }
}

// 그래프 빌드
// Nums[0] 에 따라 홀수 -> 짝수 또는 짝수 -> 홀수로 이분 그래프 빌드
void init() {
    for (int i = 0; i < N; i++) {
        vector<int> &V = (Nums[i] % 2 == Nums[0] % 2) ? X : Y;
        V.push_back(i);
    }

    for (int i = 0; i < N; i++) {
        if (Nums[i] % 2 != Nums[0] % 2) continue;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (isPrime[Nums[i] + Nums[j]]) {
                graph[i].push_back(j);
            }
        }
    }
}

bool dfs(int cur) {
    visited[cur] = true;
    for (int next : graph[cur]) {
        if (visited[B[next]]) continue;
        if (B[next] == -1 || dfs(B[next])) {
            A[cur] = next;
            B[next] = cur;
            return true;
        }
    }
    return false;
}

vector<int> solve() {
    vector<int> res;
    vector<int> all = graph[0];

    // 첫번째 수와 연결될 수 있는 모든 수에 대해 하나씩 시뮬레이션해서
    // 가능한 경우들을 res 에 담는다

    for (int k : all) {
        graph[0].clear();
        graph[0].push_back(k);

        fill(A, A + N_MAX, -1);
        fill(B, B + N_MAX, -1);

        int cnt = 0;
        for (int cur : X) {
            if (A[cur] != -1) continue;
            fill(visited, visited + N_MAX, false);
            if (dfs(cur)) cnt++;
        }

        if ((cnt << 1) == N) res.push_back(k);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    input();
    sieve();
    init();

    vector<int> res = solve();
    
    // 없으면 -1 출력
    if (res.empty()) { cout << -1; }

    // 존재하면 오름차순으로 출력
    sort(res.begin(), res.end(), [] (int &left, int &right) {
        return Nums[left] < Nums[right];
    });
    for (int k : res) { cout << Nums[k] << ' '; }

    // 최종 개행
    cout << '\n';

    return 0;
}
