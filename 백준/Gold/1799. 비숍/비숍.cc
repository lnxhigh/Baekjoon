#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using xy = pair<int,int>;

int N;
int board[10][10];
vector<xy> possibleLocationBlack;
vector<xy> possibleLocationWhite;
vector<xy> bishopLocationBlack;
vector<xy> bishopLocationWhite;

int Abs(int x) { return x > 0 ? x : -x ; }
int Max(int x, int y) { return x > y ? x : y ; }

void input(int &N, int board[10][10]) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
}

bool promising(xy loc, vector<xy> bishopLocation) {
    if (bishopLocation.empty()) return true;
    for (xy bishopLoc : bishopLocation) {
        if (Abs(bishopLoc.first - loc.first) == Abs(bishopLoc.second - loc.second)) {
            return false;
        }
    }
    return true;
}

void chess(vector<xy>& possibleLocation, vector<xy>& bishopLocation, int &answer, int start) {
    int s = possibleLocation.size();
    for (int i = start; i < s; i++) {
        xy loc = possibleLocation[i];
        if (promising(loc, bishopLocation)) {
            bishopLocation.push_back(loc);
            answer = Max(answer, bishopLocation.size());
            chess(possibleLocation, bishopLocation, answer, i+1);
            bishopLocation.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    input(N, board);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                if ((i+j) % 2 == 0) possibleLocationBlack.push_back({i,j});
                else possibleLocationWhite.push_back({i,j});
            }
        }
    }

    int answerBlack = 0, answerWhite = 0;
    chess(possibleLocationBlack, bishopLocationBlack, answerBlack, 0);
    chess(possibleLocationWhite, bishopLocationWhite, answerWhite, 0);
    cout << answerBlack + answerWhite << '\n';

    return 0;
}
