#include <bits/stdc++.h>
#define DIV 10000
using namespace std;

int N;
int D[DIV], S[DIV], L[DIV], R[DIV];
string DSLR = "DSLR";

int __D(int X) {
    return (X << 1) % DIV;
}
int __S(int X) {
    if (X == 0) return DIV - 1;
    return X - 1;
}
int __L(int X) {
    string s = to_string(X);
    if (s.size() < 4) {
        s = string(4 - s.size(), '0') + s;
    }
    string newString = s.substr(1, 3) + s.substr(0, 1);
    return stoi(newString);
}
int __R(int X) {
    string s = to_string(X);
    if (s.size() < 4) {
        s = string(4 - s.size(), '0') + s;
    }
    string newString = s.substr(3, 1) + s.substr(0, 3);
    return stoi(newString);
}

void solve(int A, int B) {
    queue<int> q;
    pair<int, int> track[10000];
    bool visited[10000] = { false, };

    q.push(A);
    visited[A] = true;

    while (!q.empty()) {
        int X = q.front();
        q.pop();
        if (X == B) break;
        
        int nexts[4] = { D[X], S[X], L[X], R[X] };
        for (int i = 0; i < 4; i++) {
            int next = nexts[i];
            if (visited[next]) continue;
            visited[next] = true;
            track[next] = { X, i };
            q.push(next);
        }
    }

    string answer = "";
    for (int i = B; i != A; i = track[i].first) {
        if (i == track[i].first) {
            cout<<"F";
            break;
        }

        answer += DSLR[track[i].second];
    }

    reverse(answer.begin(), answer.end());
    cout << answer << '\n';
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;

    for (int i = 0; i < DIV; i++) {
        D[i] = __D(i); S[i] = __S(i); L[i] = __L(i); R[i] = __R(i);
    }
    while (T--) {
        int A, B;
        cin >> A >> B;
        solve(A, B);
    }
    
    return 0;
}
