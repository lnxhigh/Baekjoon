#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;

int priority[256];

ll calc(ll x, ll y, char op) {
    if (op == '+') return x + y;
    else if (op == '-') return x - y;
    else if (op == '*') return x * y; 
    else if (op == '/') return x / y;
    return 0;
}

void handle(deque<ll> &operands, deque<char> &operators) {
    ll x1 = operands.front();
    operands.pop_front();
    ll y1 = operands.front();
    operands.push_front(x1);
    char op1 = operators.front();

    ll y2 = operands.back();
    operands.pop_back();
    ll x2 = operands.back();
    operands.push_back(y2);
    char op2 = operators.back();

    bool flag = false;

    if (priority[op1] != priority[op2]) {
        flag = (priority[op1] < priority[op2]);
    }
    else if (calc(x1, y1, op1) != calc(x2, y2, op2)) {
        flag = (calc(x1, y1, op1) > calc(x2, y2, op2));
    }
    else {
        flag = true;
    }

    if (flag) {
        operands.pop_front();
        operands.pop_front();
        operators.pop_front();
        operands.push_front(calc(x1, y1, op1));
    }
    else {
        operands.pop_back();
        operands.pop_back();
        operators.pop_back();
        operands.push_back(calc(x2, y2, op2));
    }
}

int main() {
    FastIO

    string S; cin >> S;
    int L = S.size();
    
    int idx = 0;
    deque<ll> operands;
    deque<char> operators;

    while (idx < L) {
        if (isdigit(S[idx]) || idx == 0) {
            string x;
            while (isdigit(S[idx]) || idx == 0) x.push_back(S[idx++]);
            operands.push_back(stoll(x));
        }
        else {
            char c = S[idx++];
            operators.push_back(c);
        }
    }

    priority['+'] = 4;
    priority['-'] = 4;
    priority['*'] = 3;
    priority['/'] = 3;
    
    while (!operators.empty()) {
        handle(operands, operators);
    }

    ll ans = operands.front();
    cout << ans << '\n';
    return 0;
}
