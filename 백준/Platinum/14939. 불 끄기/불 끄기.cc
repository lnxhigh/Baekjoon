#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool bulb[10][10];

void toggle(int x, int y, bool bulb[10][10]) {
    // middle, left, right, down, up
    int dx[5] = {0, 0, 0, +1, -1};
    int dy[5] = {0, -1, +1, 0, 0};

    for (int i = 0; i <= 4; i++) {
        int x_next = x + dx[i];
        int y_next = y + dy[i];
        if (x_next < 0 || x_next >= 10) continue;
        if (y_next < 0 || y_next >= 10) continue;

        bulb[x_next][y_next] ^= true; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // Input    
    for (int i = 0; i < 10; i++) {
        char line[11];
        cin >> line;
        for (int j = 0; j < 10; j++) {
            char state;
            state = line[j];
            if (state == 'O') bulb[i][j] = true;
            else if (state == '#') bulb[i][j] = false;
            else cerr << "Input Error" << '\n';
        }
    }

    // Brute Force
    vector<int> cnt;

    for (int bit = 0; bit < 1024; bit++) {
        int res = 0;
        bool temp[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                temp[i][j] = bulb[i][j];
            }
        }
        
        // first line
        for (int j = 0; j < 10; j++) {
            if (bit & (1 << j)) {
                toggle(0, j, temp);
                res++;
            }
        }

        // second line to last line
        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (temp[i-1][j]) {
                    toggle(i, j, temp);
                    res++;
                }
            }
        }

        // check if all bulbs can be turned off
        bool possible = true;
        for (int i = 0; i < 10; i++) {
            if (not possible) break;
            for (int j = 0; j < 10; j++) {
                if (temp[i][j]) {
                    possible = false;
                    break;
                }
            }
        }

        if (possible) {
            cnt.push_back(res);
        }
    }

    int answer;
    if (cnt.empty()) answer = -1;
    else answer = *min_element(cnt.begin(), cnt.end());
    cout << answer;

    return 0;
}