#include <bits/stdc++.h>
using namespace std;

string f(int x, int degree) {
    if (degree == 0) return "+W";
    if (x == 0) return "";

    string res = x > 0 ? "+" : "-";
    if (abs(x) != 1) res += to_string(abs(x));
    res += string(degree, 'x');
    return res;
}

string solve(string expression) {
    int var = expression.find('x');
    if (var == string::npos) var = -1;
    
    int coef = (var != -1) ? stoi(expression.substr(0, var)) / 2 : 0;
    int constant = ((int) expression.size() != var+1) ? stoi(expression.substr(var+1)) : 0;

    string res = f(coef, 2) + f(constant, 1) + f(0, 0);
    int start = (res[0] == '+') ? 1 : 0;
    res = res.substr(start);
    return res;
}

int main() {
    string expression;
    cin >> expression;
    string res = solve(expression);
    cout << res << '\n';
    return 0;
}
