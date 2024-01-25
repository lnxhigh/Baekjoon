#include <iostream>
#include <queue>
#define MAX_ROW 1000
#define MAX_COL 1000

using namespace std;

int arr[MAX_ROW][MAX_COL] = {0, };
int visited[MAX_ROW][MAX_COL] = {false, };
int M, N;
queue<int> xs;
queue<int> ys;

void print(void) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N;

    // Initilization
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 1) {
                xs.push(i); ys.push(j);
                visited[i][j] = true;
            }
        }
    }

    int x, y;
    int cnt = xs.size(); // Count the level
    int size = xs.size(); // Check if the queue is empty
    int level = 0;

    while (size > 0) {
        x = xs.front(); y = ys.front();

        xs.pop(); ys.pop();
        cnt--; size--;
        
        // Visit adjacent nodes (x+1, y) (x-1, y) (x, y-1) (x, y+1)
        if ((x+1 <= N-1) and (not visited[x+1][y])) {
            visited[x+1][y] = true;
            if (arr[x+1][y] == 0) {
                arr[x+1][y] = 1;
                xs.push(x+1); ys.push(y);
                size++;
            }
        }


        if ((x-1 >= 0) and (not visited[x-1][y])) {
            visited[x-1][y] = true;
            if (arr[x-1][y] == 0) {
                arr[x-1][y] = 1;
                xs.push(x-1); ys.push(y);
                size++;
            }
        }
        if ((y+1 <= M-1) and (not visited[x][y+1])) {
            visited[x][y+1] = true;
            if (arr[x][y+1] == 0) {
                arr[x][y+1] = 1;
                xs.push(x); ys.push(y+1);
                size++;
            }
        }
        if ((y-1 >= 0) and (not visited[x][y-1])) {
            visited[x][y-1] = true;
            if (arr[x][y-1] == 0) {
                arr[x][y-1] = 1;
                xs.push(x); ys.push(y-1);
                size++;
            }
        }

        // Update the level
        if (cnt == 0) {
            cnt = size;
            level++;
            // print();
        }
    }
    
    level--;

    // Check if there is zero
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) {
                level = -1;
                break;
            }
        }
    }

    cout << level;

    return 0;
}