#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 10001;

int N, Capacity;
int M;
tuple<int,int,int> Boxes[MAX];

int Truck[MAX]; // 트럭이 가진 박스의 수량
priority_queue<pair<int,int>> pq;

int main() {
    FastIO
    cin >> N >> Capacity;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int from, to, cnt;
        cin >> from >> to >> cnt;
        --from, --to;
        Boxes[i] = { from, to, cnt };
    }
    sort(Boxes, Boxes + M);

    int ans = 0; // 트럭이 배송한 박스 수
    int weight = 0; // 현재 트럭이 싣고 있는 박스들의 무게
    int cur = 0; // 현재 실어야 하는 박스

    // 트럭을 전진시킨다
    for (int i = 0; i < N; i++) {

        // 박스를 내린다
        for (int box = 0; box < M; box++) {
            auto [from, to, amt] = Boxes[box];
            if (to != i) continue;
            
            int& cnt = Truck[box];
            ans += cnt;
            weight -= cnt;
            cnt = 0;
        }

        // 박스를 싣는다
        while (cur < M) {
            auto [from, to, amt] = Boxes[cur];
            if (from != i) break;

            // 남은 용량이 있으면 최대한 싣는다
            if (weight < Capacity) {
                int diff = Capacity - weight;
                int cnt = min(amt, diff);
                
                Truck[cur] += cnt;
                weight += cnt;
                amt -= cnt;
            }

            // 남은 용량이 없으면 기존의 박스를 확인한다
            // 기존 박스의 도착 시점이 현재 박스의 도착 시점보다 늦으면 버린다
            while (!pq.empty() && amt > 0) {
                auto [last, prv] = pq.top();
                if (to >= last) break;

                int cnt = min(Truck[prv], amt);

                amt -= cnt;

                Truck[prv] -= cnt;
                Truck[cur] += cnt;

                if (Truck[prv] == 0) {
                    pq.pop();
                }
            }
            
            pq.push({ to, cur });
            cur++;
        }
    }

    cout << ans << '\n';
    return 0;
}
