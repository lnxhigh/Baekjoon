#include <iostream>
#include <string>
#include <stack>

using namespace std;

string String;
string explosion;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> String;
    cin >> explosion;

    int N_explosion = explosion.length();
    int N_String = String.length();
    int cnt = 0;

    stack<char> alpha;
    stack<char> beta;

    for (int i = 0; i < N_String; i++) {
        alpha.push(String[i]);
        
        if (alpha.top() == explosion[cnt]) {
            cnt++;
            if (cnt == N_explosion) {
                cnt = 0;

                for (int k = 0; k < N_explosion; k++) {
                    alpha.pop();
                }
        
                for (int k = 0; k < N_explosion-1; k++) {
                    if (alpha.empty()) break;
                    beta.push(alpha.top());
                    alpha.pop();
                }

                for (int k = 0; k < N_explosion-1; k++) {
                    if (beta.empty()) break;
                    alpha.push(beta.top());
                    beta.pop();

                    if (alpha.top() == explosion[cnt]) {
                        cnt++;
                    }
                    else {
                        cnt = 0;
                        if (alpha.top() == explosion[cnt]) {
                            cnt++;
                        }
                    }
                }
            }
        }
        else {
            cnt = 0;
            if (alpha.top() == explosion[cnt]) {
                cnt++;
            }
        }
    }

    if (alpha.empty()) {
        cout << "FRULA";
        return 0;
    }
    
    while (not alpha.empty()) {
        beta.push(alpha.top());
        alpha.pop();
    }
    
    while (not beta.empty()) {
        cout << beta.top();
        beta.pop();
    }
    return 0;
}