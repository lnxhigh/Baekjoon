#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

string S, P;
int F[MAX];

// 지금까지 공부한 알고리즘 중에 제일 어려운 것 같다 ...
// blog.naver.com/kks227/220917078260

int main() {
    getline(cin, S);
    getline(cin, P);
    
    // 실패 함수
    for (int i = 1, k = 0; i < P.size(); i++) {
        while (k > 0 && P[i] != P[k]) k = F[k-1];
        if (P[i] == P[k]) F[i] = ++k;
    }

    // 패턴 매칭
    vector<int> res;
    for (int i = 0, k = 0; i < S.size(); i++) {
        while (k > 0 && S[i] != P[k]) k = F[k-1];
        if (S[i] == P[k]) k++;
        
        if (k == P.size()) {
            res.push_back(i+1-k);
            k = F[k-1];
        }
    }

    cout << res.size() << '\n';
    for (int i : res) cout << i+1 << ' ';
    cout << '\n';
    return 0;
}
