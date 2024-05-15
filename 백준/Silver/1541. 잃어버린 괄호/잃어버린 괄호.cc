#include <bits/stdc++.h>
using namespace std;

string expression;
int arr[50];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> expression;

    string newExpression = "";
    for (char letter : expression) {
        if (letter >= '0' && letter <= '9') newExpression += letter;
        else {
            newExpression += " ";
            newExpression += letter;
        }
    }
    
    stringstream ss(newExpression);
    string s;
    int N = 0;
    while (ss >> s) {
        arr[N++] = stoi(s);
    }

    int m = N;
    for (int i = 0; i < N; i++) {
        if (arr[i] < 0) {
            m = i;
            break;
        }
    }
    
    int answer = 0;
    for (int i = 0; i < N; i++) {
        int value = arr[i];
        if (i >= m) {
            value = (value < 0) ? value : -value;
        }
                
        answer += value;
    }

    std::cout << answer << '\n';
    
    return 0;
}
