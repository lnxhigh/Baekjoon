#include <bits/stdc++.h>

using namespace std;
int zero = 0, one = 0;
vector<vector<int>> Arr;

void add(int x, int y) {
    if (Arr[x][y]) one++;
    else zero++;
    return;
}

bool check(int x, int y, int N) {
    int k = Arr[x][y];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (k != Arr[x+i][y+j]) 
                return false;
        }
    }
    return true;
}

void f(int x, int y, int N) {
    if (check(x, y, N)) {
        add(x, y);
        return;
    }
    
    int xs[4] = { x, x    , x+N/2, x+N/2 };
    int ys[4] = { y, y+N/2, y    , y+N/2 };
    for (int i = 0; i < 4; i++) {
        f(xs[i], ys[i], N/2);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    Arr = arr;
    int N = arr.size();
    
    f(0, 0, N);
    
    vector<int> answer = { zero, one };
    return answer;
}