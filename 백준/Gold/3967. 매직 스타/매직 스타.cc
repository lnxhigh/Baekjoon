#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

char star[5][9];
set<char> used;

vector<char> x;
vector<pair<int,int>> coord;

pair<int,int> lines[6][4] = {
    { { 1, 1 }, { 1, 3 }, { 1, 5 }, { 1, 7 } },
    { { 3, 1 }, { 3, 3 }, { 3, 5 }, { 3, 7 } },
    { { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 } },
    { { 1, 7 }, { 2, 6 }, { 3, 5 }, { 4, 4 } },
    { { 0, 4 }, { 1, 3 }, { 2, 2 }, { 3, 1 } },
    { { 0, 4 }, { 1, 5 }, { 2, 6 }, { 3, 7 } }
};

bool isMagic() {
    for (int i = 0; i < 6; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            const auto& [xij, yij] = lines[i][j];
            sum += (int) (star[xij][yij] - 'A' + 1);
        }
        if (sum != 26) return false;
    }

    return true;
}

int main() {
    FastIO
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            char c; cin >> c;
            star[i][j] = c;
            if (c >= 'A' && c <= 'Z') used.insert(c);
        }
    }

    char c = 'A';
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            if (star[i][j] != 'x') continue;
            while (used.find(c) != used.end()) c++;
            
            x.push_back(c);
            used.insert(c++);
            coord.push_back({ i, j });
        }
    }

    do {
        for (size_t k = 0; k < x.size(); k++) {
            const auto& [i, j] = coord[k];
            star[i][j] = x[k];
        }
        if (isMagic()) break;
    } while (next_permutation(x.begin(), x.end()));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            cout << star[i][j];
        }
        cout << '\n';
    }

    return 0;
}
