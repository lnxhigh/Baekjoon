#include <bits/stdc++.h>
using namespace std;

int N, M;
string S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    cin >> S;

    string p = "I";
    for (int i = 0; i < N; i++) {
        p += "OI";
    }

    int answer = 0;
    int pos = 0;
    int len = 2*N + 1;

    while (true) {
        int i = S.find(p, pos);
        if (i == string::npos) break;

        pos = i + len;
        answer++; 

        while (pos + 1 < M) {
            if (S.substr(pos, 2) != "OI") break;
            answer++;
            pos += 2;
        }
    }
    
    cout << answer << '\n';
    
    return 0;
}
