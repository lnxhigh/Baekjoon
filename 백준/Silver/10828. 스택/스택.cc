#include <iostream>
#include <string>
#include <stack>
using namespace std;

int N;
int x;
string operation;
stack<int> list;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> operation;

        if (operation == "push") {
            cin >> x;
            list.push(x);
        }
        else if (operation == "pop") {
            if (list.empty()) {
                cout << -1 << '\n';
                continue;
            }
        
            x = list.top();
            list.pop();
            cout << x << '\n';
        }
        else if (operation == "size") {
            cout << list.size() << '\n';
        }
        else if (operation == "empty") {
            cout << list.empty() << '\n';
        }
        else if (operation == "top") {
            if (list.empty()) {
                cout << -1 << '\n';
                continue;
            }
            cout << list.top() << '\n';
        }
    }    
}