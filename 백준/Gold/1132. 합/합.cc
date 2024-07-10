#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 50;
string S[N_MAX];
pair<long long, int> X[10];
long long ans;

bool cannotBeZero[10];

void f(const string &str) {
    int size = str.size();
    long long res = 0;
    long long mul = 1;

    for (int i = size-1; i >= 0; i--) {
        int k = str[i] - 'A';
        X[k].first += mul;
        mul *= 10;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    // 더했을 때 가장 값이 큰 순서대로 정렬
    for (int i = 0; i < 10; i++) X[i].second = i;
    for (int i = 0; i < N; i++) f(S[i]);
    sort(X, X + 10);
    
    // 0으로 시작하는 수를 예외처리
    for (int i = 0; i < N; i++) {
        cannotBeZero[S[i][0]-'A'] = true;
    }

    int nonZeroIdx = 0;
    for (int i = 0; i < 10; i++) {
        if (!cannotBeZero[X[i].second]) {
            nonZeroIdx = i;
            break;
        }
    }

    // 앞자리가 0으로 시작하면 0으로 시작하지 않는 가장 작은 수를
    // 가장 뒷자리로 밀어낸다
    if (nonZeroIdx != 0) {
        pair<long long, int> tmp = X[nonZeroIdx];
        for (int i = nonZeroIdx; i > 0; i--) {
            X[i] = X[i-1];
        }
        X[0] = tmp;
    }

    // 결과 출력
    for (int i = 0; i < 10; i++) {
        ans += X[i].first * i;
    }

    cout << ans << '\n';
    return 0;
}
