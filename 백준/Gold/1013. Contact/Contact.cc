#include <bits/stdc++.h>
using namespace std;

// FSM 구현 실패함 ...
// 내일 다시 시도하자

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    regex pattern("(100+1+|01)+");

    cin >> T;
    for (int t = 0; t < T; t++) {
        string signal;
        cin >> signal;
        string answer = regex_match(signal, pattern) ? "YES" : "NO";
        cout << answer << '\n';
    }

    return 0;    
}
