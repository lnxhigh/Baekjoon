#include <iostream>
#include <map>
using namespace std;

int number[11];
map<char, int> n_operation;
char operators[4] = { '+', '-', '*', '/' };
int N;
int minimum = 1 << 30;
int maximum = -(1 << 30);
int temp;
int Min(int x, int y) { return x < y ? x : y ; }
int Max(int x, int y) { return x > y ? x : y ; }

void dfs(int i) {
    if (i == N) {
        maximum = Max(maximum, temp);
        minimum = Min(minimum, temp);
        return;
    }
    for (char op : operators) {
        if (n_operation[op] > 0) {
            n_operation[op]--;
            int x = temp;
            if      (op == '+') { temp += number[i]; }
            else if (op == '-') { temp -= number[i]; }
            else if (op == '*') { temp *= number[i]; }
            else if (op == '/') { temp /= number[i]; }
            dfs(i+1);
            temp = x;
            n_operation[op]++;
        }
    }
}

int main(void) {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> number[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> n_operation[operators[i]];
    }
    
    temp = number[0];
    dfs(1);
    
    cout << maximum << '\n';
    cout << minimum << '\n';

    return 0;
}