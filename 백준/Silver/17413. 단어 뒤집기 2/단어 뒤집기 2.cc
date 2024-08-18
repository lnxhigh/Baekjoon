#include <bits/stdc++.h>
using namespace std;

string S;
stack<char> front, back;
bool isTag;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    getline(cin, S);
    S += ' ';
    int L = S.size();

    for (int i = 0; i < L; i++) {
        char cur = S[i];
        if (isalpha(cur) || isdigit(cur)) {
            back.push(cur);
        }
        else if (cur == ' ') {
            if (!isTag) {
                while (!back.empty()) {
                    cout << back.top();
                    back.pop();
                }
                cout << cur;
            }
            else {
                back.push(cur);
            }
        }
        else if (cur == '<' || cur == '>') {
            if (cur == '<') {
                isTag = true;
                while (!back.empty()) {
                    cout << back.top();
                    back.pop();
                }
                back.push(cur);
            }
            else if (cur == '>') {
                isTag = false;
                back.push(cur);

                while (!back.empty()) {
                    front.push(back.top());
                    back.pop();
                }
                while (!front.empty()) {
                    cout << front.top();
                    front.pop();
                }
            }
        }
    }

    return 0;
}
