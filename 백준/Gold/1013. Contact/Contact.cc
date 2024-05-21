#include <bits/stdc++.h>
using namespace std;

enum { TRAP_STATE = -1, INIT_STATE, Q1, Q2, Q3, Q4, Q5, Q6, R1 };

// (100+1+ | 01)+
void transition(int &state, int bit) {
    switch (state)
    {
        case INIT_STATE: state = bit ? Q1 : R1; break;
        case Q1: state = bit ? TRAP_STATE : Q2; break;
        case Q2: state = bit ? TRAP_STATE : Q3; break;
        case Q3: state = bit ? Q4 : Q3; break;
        case Q4: state = bit ? Q5 : R1; break;
        case Q5: state = bit ? Q5 : Q6; break;
        case Q6: state = bit ? INIT_STATE : Q3; break;
        case R1: state = bit ? INIT_STATE : TRAP_STATE; break;
        default: state = TRAP_STATE; break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;

    cin >> T;
    for (int t = 0; t < T; t++) {
        string signal;
        cin >> signal;
        int state = 0;
        for (char bit : signal) {
            transition(state, bit - '0');
        }

        bool match = false;
        for (int finish : { INIT_STATE, Q4, Q5 }) {
            if (state == finish) match = true;
        }
        string answer = match ? "YES" : "NO";
        cout << answer << '\n';
    }

    return 0;    
}
