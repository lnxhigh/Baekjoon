#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N, M;
const int N_MAX = 300000;
const int INF = 1 << 30;
vector<pair<int,int>> line;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    // 순방향으로 가는 이동 거리는 M 이 최소
    // 역방향으로 가는 이동 거리를 최소화하면 된다
    // 역방향 이동 거리의 최솟값은 역방향으로 그어진 선의 길이가 된다
    // 이는 스위핑으로 구할 수 있다
    
    for (int i = 0; i < N; i++) {
        int from, to;
        cin >> from >> to;
        if (from > to) line.push_back({ to, from });
    }

    // 가장 효율적인 역방향 이동 - 스위핑
    sort(line.begin(), line.end());
    int left = -INF, right = -INF;
    int L = line.size();

    // 오버플로우 ?
    ll dist = 0;
    for (int i = 0; i < L; i++) {
        if (line[i].first < right) {
            right = max(right, line[i].second);
        }
        else {
            dist += 1LL * (right - left);
            left = line[i].first;
            right = line[i].second;
        }
    }
    dist += 1LL * (right - left);

    // 역방향 이동 후 다시 원래 자리로 돌아오기 위해 두 배를 한다
    dist *= 2LL;

    // 순방향 이동
    dist += 1LL * M;

    // 전체 이동 거리 출력
    cout << dist << '\n';

    return 0;
}
