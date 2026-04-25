#include <iostream>
#include <string>
using namespace std;

int M;
int S = 0;
string operation;
int x, y;

int main(void) { 
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> M;
    
    for (int m = 0; m < M; m++) {
        cin >> operation;
        if (operation == "all") { S = ~0; continue; }
        else if (operation == "empty") { S = 0; continue; }
        
        cin >> x; 
        y = 1 << x;
        if (operation == "add") { S = S | y; } 
        else if (operation == "remove") { S = S & (~y); }
        else if (operation == "check") { cout << ((S & y) >> x) << '\n'; }
        else if (operation == "toggle") { S = S ^ y; }
    }

    return 0;
}