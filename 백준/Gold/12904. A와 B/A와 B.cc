#include <bits/stdc++.h>
using namespace std;

string S, T;
deque<char> dq;
bool reversed = false;

int main() {
    cin >> S >> T;
    for (char c : T) dq.push_back(c);

    while (S.size() != dq.size()) {
        char last = reversed ? dq.front() : dq.back();
        reversed ? dq.pop_front() : dq.pop_back();

        reversed ^= (last == 'B');
    }
    
    bool check = true;
    for (int i = 0; i < (int) S.size(); i++) {
        char first = reversed ? dq.back() : dq.front();
        reversed ? dq.pop_back() : dq.pop_front();
        
        if (first != S[i]) check = false;
        if (!check) break;
    }

    cout << check << '\n';
    return 0;
}
