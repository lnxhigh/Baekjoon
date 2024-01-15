#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
using xy = pair<int,int>;

int T;

void input(int &h, int &w, char plan[102][102], int keys[26]) {
    cin >> h >> w;

    char line[101];
    for (int i = 1; i <= h; i++) {
        cin >> line;
        for (int j = 1; j <= w; j++) {
            plan[i][j] = line[j-1];
        }
    }

    string key_str;
    
    cin >> key_str;
    if (key_str == "0") {
        return;
    }

    for (char key : key_str) {
        keys[toupper(key) - 'A']++;
    }
}

void print(int &h, int &w, char plan[102][102], int keys[26], bool visited[102][102]) {
    cout << '\n';
    
    cout << "keys: ";
    for (int i = 0; i < 26; i++) {
        if (keys[i] > 0) { 
            char x = ('A' + i);
            cout << x << ' '; 
        }
    }
    
    cout << "\n\n";

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cout << plan[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "\n\n";
}

void initialize(const int h, const int w, char plan[102][102], bool visited[102][102], vector<xy> &door, int keys[26], int &cnt) {
    vector<int> x, y;
    
    for (int i = 0; i <= h+1; i++) { x.push_back(i); y.push_back(0); }
    for (int i = 0; i <= h+1; i++) { x.push_back(i); y.push_back(w+1); }
    for (int i = 0; i <= w+1; i++) { x.push_back(0); y.push_back(i); }
    for (int i = 0; i <= w+1; i++) { x.push_back(h+1); y.push_back(i); }

    int s = x.size();
    for (int i = 0; i < s; i++) {
        int a = x[i], b = y[i];
        
        plan[a][b] = '.';
        visited[a][b] = true; 
        door.push_back({a,b});
    }
}

void infiltrate(const int h, const int w, char plan[102][102], int keys[26], bool visited[102][102], vector<xy> &door, int &cnt) {
    vector<xy> moves = {{-1,0}, {+1,0}, {0,-1}, {0,+1}};

    queue<xy> q;
    for (xy start : door) {
        q.push(start);
    }
    door.clear();
    
    while (not q.empty()) {
        xy cur = q.front();
        q.pop();
        for (xy m : moves) {
            xy next = { cur.first + m.first, cur.second + m.second };
            if (next.first <= 0 or next.first >= h+1) continue;
            if (next.second <= 0 or next.second >= w+1) continue;
            if (visited[next.first][next.second]) continue;

            visited[next.first][next.second] = true;
            char x = plan[next.first][next.second];
            
            if (x == '*') {
                continue;
            }
            else if (x == '.') {
                q.push(next);
            }
            else if (x == '$') {
                cnt++;
                plan[next.first][next.second] = '.';
                q.push(next);
            }
            else if (x >= 'a' and x <= 'z') {
                plan[next.first][next.second] = '.';
                q.push(next);
                keys[toupper(x) - 'A']++;
            }
            else if (x >= 'A' and x <= 'Z') {
                bool unlock = (keys[x - 'A'] > 0);
                if (unlock) {
                    visited[cur.first][cur.second] = true;
                    plan[next.first][next.second] = '.';
                    q.push(next);
                }
                else {
                    door.push_back(cur);
                    visited[next.first][next.second] = false;
                }
            }
        }
    }
    
}

int get_n_keys(int arr[], int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> T;
    for (int t = 0; t < T; t++) {
        int h, w;
        char plan[102][102];
        bool visited[102][102] = {false,};
        int cnt = 0;
        int keys[26] = {0,};
        vector<xy> door;

        input(h, w, plan, keys);
        initialize(h, w, plan, visited, door, keys, cnt);
        // print(h, w, plan, keys, visited);
        int n_keys_prev = get_n_keys(keys, 26);

        infiltrate(h, w, plan, keys, visited, door, cnt);
        // print(h, w, plan, keys, visited);
        int n_keys_cur = get_n_keys(keys, 26);
        
        while (n_keys_prev != n_keys_cur) { // until no key is earned
            n_keys_prev = n_keys_cur;
            infiltrate(h, w, plan, keys, visited, door, cnt);
            // print(h, w, plan, keys, visited);
            n_keys_cur = get_n_keys(keys, 26);
        }
        
        cout << cnt << '\n';
    }
    
    return 0;
}