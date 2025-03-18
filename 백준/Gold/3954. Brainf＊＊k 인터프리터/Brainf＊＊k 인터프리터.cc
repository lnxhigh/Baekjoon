#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using uint = unsigned int;

int main() {
    FastIO
    
    int TC; cin >> TC;
    while (TC--) {
        int sm, sc, si; cin >> sm >> sc >> si;
        string program; cin >> program;
        string input; cin >> input;

        uint pc = 0;
        uint cnt = 0;
        bool loop = false;
        bool finish = false;

        vector<unsigned char> data(sm);
        uint ptr = 0;
        uint minpc = sc, maxpc = 0;
        uint pos = 0;
        
        stack<uint> st;
        vector<uint> l(sc), r(sc);

        for (uint i = 0; i < program.size(); i++) {
            if (program[i] == '[') {
                st.push(i);
            }
            else if (program[i] == ']') {
                int j = st.top();
                l[j] = i, r[i] = j;
                st.pop();
            }
        }

        while (pc < program.size() && cnt <= 100'000'000) {
            char instruction = program[pc];

            switch (instruction)
            {
            case '-':
                data[ptr]--;
                break;

            case '+':
                data[ptr]++;
                break;

            case '<':
                ptr = (ptr + sm - 1) % sm;
                break;

            case '>':
                ptr = (ptr + 1) % sm;
                break;

            case '[':
                if (data[ptr] == 0) {
                    pc = l[pc];
                }
                break;

            case ']':
                if (data[ptr] != 0) {
                    pc = r[pc];
                }
                break;
            
            case ',':
                data[ptr] = 255;
                if (pos < si) data[ptr] = input[pos++];
                break;
            
            default:
                break;
            }

            pc++;
            cnt++;
            
            if (cnt >= 50'000'000) {
                loop = (pc < program.size());
            }
            
            if (loop) {
                minpc = min(minpc, pc);
                maxpc = max(maxpc, pc);
            }
        }

        if (loop) {
            cout << "Loops " << --minpc << ' ' << maxpc << '\n';
        }
        else {
            cout << "Terminates" << '\n';
        }
    }

    return 0;
}
