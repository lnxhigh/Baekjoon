#include <bits/stdc++.h>
using namespace std;

// 히스토그램에서 가장 큰 직사각형의 넓이는 가장 낮은 높이에 의해 제한된다
// 기존에 저장해 둔 높이보다 낮은 높이가 나오면 기존에 정보는 더 이상 살펴볼 필요가 없다
// 따라서 전부 pop 을 하면서 최대 넓이를 업데이트하는 전략을 사용

// H[N] = -1 로 설정하는 이유
// 마지막에 스택에 남은 모든 원소들을 pop 하면서 최댓값을 업데이트하기 위해서
// 면적 계산 로직은 문제 없어 보인다

// st.top().H >= H[i] 에서 등호 붙인 이유
// 같은 높이가 스택에 등장했을 때 처리하는 것이 까다로움
// 같은 높이일 때도 전부 pop 시켜버려도 문제 없는 것 같다 (과연?)

// k 는 지금까지 삭제한 히스토그램 막대들의 개수를 나타낸다
// 이를 바탕으로 새롭게 만들어지는 직사각형을 삽입할 수 있다
// 맞았으면 좋겠다 (맞왜틀?)

int N;
const int N_MAX = 100001;
int H[N_MAX];

struct Rect { int W, H; };
stack<Rect> st;
int area = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) { cin >> H[i]; }
    H[N++] = -1;

    for (int i = 0; i < N; i++) {
        int k = 0;
        while (!st.empty() && st.top().H >= H[i]) {
            int w = st.top().W + k;
            int h = st.top().H;
            area = max(area, w * h);
            k += st.top().W;
            st.pop();
        }

        st.push({ ++k, H[i] });
    }

    cout << area << '\n';
    return 0;
}
