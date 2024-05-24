#include <bits/stdc++.h>
using namespace std;

int N, M;
unordered_set<string> strings;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        strings.insert(s);
    }

    int answer = 0;
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        if (strings.count(s)) answer++;
    }

    cout << answer << '\n';
    
    return 0;
}
