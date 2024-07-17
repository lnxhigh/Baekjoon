#include <bits/stdc++.h>
using namespace std;

string locKing, locStone;
int N;
const int MAX = 8;

class Piece {
    public:
    int row, col;
    unordered_map<string,pair<int,int>> table = {
        {"R", {0, 1}}, {"L", {0, -1}}, {"B", {-1, 0}}, {"T", {1, 0}},
        {"RT", {1, 1}}, {"LT", {1, -1}}, {"RB", {-1, 1}}, {"LB", {-1, -1}},
    };

    Piece(string loc) {
        this->col = loc[0] - 'A' + 1;
        this->row = loc[1] - '0';
    }

    bool isMoveAllowed(string movement) {
        pair<int,int> next = table[movement];
        int nextRow = row + next.first;
        int nextCol = col + next.second;

        if (nextRow <= 0 || nextRow > MAX || nextCol <= 0 || nextCol > MAX) return false;
        return true;
    }

    bool isMoveAllowed(string movement, Piece* constraint) {
        pair<int,int> next = table[movement];
        int nextRow = row + next.first;
        int nextCol = col + next.second;

        if (nextRow <= 0 || nextRow > MAX || nextCol <= 0 || nextCol > MAX) return false;

        if (nextRow == constraint->row && nextCol == constraint->col) {
            if (!constraint->isMoveAllowed(movement)) return false;
        }
        
        return true;
    }

    void Move(string movement) {
        pair<int,int> next = table[movement];
        this->row = row + next.first;
        this->col = col + next.second;
    }

    void Print() {
        char c = 'A' + this->col - 1;
        char r = '0' + this->row;
        cout << c << r << '\n';
    }
};

int main() {
    cin >> locKing >> locStone;
    Piece* king = new Piece(locKing);
    Piece* stone = new Piece(locStone);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string movement;
        cin >> movement;

        if (king->isMoveAllowed(movement, stone)) {
            king->Move(movement);
            if (king->row == stone->row && king->col == stone->col) stone->Move(movement);
        }
    }

    king->Print();
    stone->Print();
    return 0;
}
