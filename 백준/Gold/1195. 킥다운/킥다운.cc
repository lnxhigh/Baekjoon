#include <bits/stdc++.h>
using namespace std;

int N;
string top, bottom;

bool check(string newTop, string newBottom) {
    for (int i = 0; i < newTop.size(); i++) {
        if (newTop[i] == '2' && newBottom[i] == '2') return false;
    }
    return true;
}

int len(string newTop, string newBottom) {
    int res = 0;
    for (int i = 0; i < newTop.size(); i++) {
        if (newTop[i] != '0' || newBottom[i] != '0') res++;
    }

    return res;
}

int solve(string top, string bottom) {
    int answer = top.size() + bottom.size() + 1;
    string newBottom = string(top.size(), '0') + bottom + string(top.size(), '0');

    for (int i = 0; i <= top.size() + bottom.size(); i++) {
        string newTop = string(i, '0') + top + string(top.size() + bottom.size() - i, '0');
        if (check(newTop, newBottom)) {
            answer = min(answer, len(newTop, newBottom));
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> top >> bottom;
    cout << solve(top, bottom) << '\n';
    
    return 0;
}
