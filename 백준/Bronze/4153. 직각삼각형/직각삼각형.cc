#include <iostream>
#include <string>
using namespace std;

int a, b, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    while (true) {
        cin >> a >> b >> c;

        if (a*a + b*b + c*c == 0) break;

        string answer = "wrong";
        if (a*a + b*b == c*c) answer = "right";
        if (b*b + c*c == a*a) answer = "right";
        if (c*c + a*a == b*b) answer = "right";
        
        cout << answer << '\n';
    }   

    return 0;
}