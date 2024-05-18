#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int n = board.size();
    int count = 0;
    int dh[4] = { 0, 1, -1, 0 };
    int dw[4] = { 1, 0, 0, -1 };
    
    for (int i = 0; i < 4; i++) {
        int h_check = h + dh[i];
        int w_check = w + dw[i];
        
        if (h_check < 0 || h_check >= n) continue;
        if (w_check < 0 || w_check >= n) continue;
        
        if (board[h][w] == board[h_check][w_check]) {
            count++;
        }
    }
    
    return count;
}