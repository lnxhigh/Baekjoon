#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 50;
vector<int> Crane;

int M;
const int M_MAX = 10000;
multiset<int> Box;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력 처리
    cin >> N;
    Crane.reserve(N_MAX);
    for (int i = 0; i < N; i++) {
        int V;
        cin >> V;
        Crane.push_back(V);
    }
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        int W;
        cin >> W;
        Box.insert(W);
    }

    // 박스를 모두 배로 옮길 수 없는 경우 처리
    sort(Crane.begin(), Crane.end(), [] (int &x, int &y) { return x > y; });
    if (*Crane.begin() < *Box.rbegin()) {
        cout << -1 << '\n';
        return 0;
    }
    
    // 시간의 최솟값 구하기
    int res = 0;
    while (true) {
        if (Box.empty()) break;

        for (int i = 0; i < N; i++) {
            auto iter = Box.upper_bound(Crane[i]);
            if (iter == Box.begin()) continue;
            Box.erase(--iter);
        }

        res++;
    }

    // 결과 출력
    cout << res << '\n';
    return 0;
}
