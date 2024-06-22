#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
const int N_MAX = 500000;
int A[N_MAX];
ll res = 0LL;

stack<pair<int,int>> st;
vector<pair<int,int>> heights;

// 너무 어렵다 ... 맞았으면 좋겠다 ...

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 개수 압축
    int curHeight = A[0];
    int cnt = 0;
    for (int i = 1; i < N; i++) {
        if (curHeight != A[i]) {
            heights.push_back({ curHeight, ++cnt });
            cnt = 0;
            curHeight = A[i];
        }
        else {
            cnt++;
        }
    }
    heights.push_back({ curHeight, ++cnt });

    // 키가 같은 사람끼리 서로 볼 수 있는 쌍의 수
    for (const pair<int,int> &p : heights) {
        int k = p.second;
        res += 1LL * k * (k-1) / 2;
    }

    // 내림차순 스택 이용
    // 키가 큰 사람이 나오면 이전 사람은 그 이후 사람을 볼 수 없으므로
    // 기존에 있던 사람들을 모두 처리해줄 수 있다
    int L = heights.size();

    for (int i = 0; i < L; i++) {
        pair<int,int> cur = heights[i];

        // 동일한 키가 스택에 연속해서 들어가는 경우
        // 그 이후의 쌍을 계산하는데 문제가 생기는데
        // 이와 같은 경우 같은 키를 가진 모든 쌍의 개수를 병합해서 처리했음

        // while 문에서 만약 부등호로 greater or equal 이 아닌 greater 을 쓰면
        // 이전의 쌍을 계산하는 데 있어서 누락이 생김
        // 부등호로 greater or equal 을 쓰면 이후의 쌍을 계산하는 데 있어서 누락이 생김
        // 이를 같은 키를 가진 쌍을 병합해서 해결 가능하다고 생각했음

        int value = heights[i].second;

        while (!st.empty() && st.top().first <= heights[i].first) {
            pair<int,int> next = st.top();
            st.pop();

            if (next.first == heights[i].first) {
                value += next.second;
                res += 1LL * next.second * heights[i].second;
            }
            else {
                res += 1LL * next.second;
            }

            cur = next;
        }

        // 내림차순을 형성하며 스택에 쌓을 때
        // 기존에 있던 앞사람과 쌍을 형성
        // 키가 작은 사람의 수만큼 쌍을 형성
        if (!st.empty()) {
            res += 1LL * heights[i].second;
        }

        st.push({ heights[i].first, value });
    }
    
    cout << res << '\n';

    return 0;
}
