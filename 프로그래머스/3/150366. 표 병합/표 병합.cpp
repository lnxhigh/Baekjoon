#include <bits/stdc++.h>

using namespace std;
const int n = 50;

string arr[n][n];
int group[n][n];
int t = 0;

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

vector<string> split(const string &line) {
    vector<string> result;
    stringstream ss(line);
    string buffer;
    
    while (ss >> buffer) result.push_back(buffer);
    return result;
}

void update(int r, int c, string value) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (group[x][y] == group[r][c]) {
                arr[x][y] = value;
            }
        }
    }
}

void update(string value1, string value2) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (arr[x][y] == value1) {
                arr[x][y] = value2;
            }
        }
    }
}

void merge(int r1, int c1, int r2, int c2) {    
    string v1 = arr[r1][c1], v2 = arr[r2][c2];
    int t1 = group[r1][c1], t2 = group[r2][c2];

    string value;
    if (not v1.empty()) value = v1;
    else if (not v2.empty()) value = v2;
    
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (group[x][y] == t1 or group[x][y] == t2) {
                arr[x][y] = value;
                group[x][y] = t;
            }
        }
    }
}

void unmerge(int r, int c) {
    string v1 = arr[r][c];
    int t0 = group[r][c];
    
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (group[x][y] != t0) continue;
            
            arr[x][y] = "";
            group[x][y] = t++;
        }
    }
    
    arr[r][c] = v1;
}

string print(int r, int c) {
    if (arr[r][c].empty()) return "EMPTY";
    return arr[r][c];
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    // Init
    
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            group[x][y] = t++;
        }
    }
    
    // Process
    
    for (const string &command : commands) {
        auto args = split(command);
        string op = args[0];
        t++;
        
        if (op == "UPDATE") {
            if (args.size() <= 3) {
                string value1 = args[1], value2 = args[2];
                update(value1, value2);
            }
            else if (args.size() <= 4) {
                int r = stoi(args[1]) - 1, c = stoi(args[2]) - 1;
                string value = args[3];
                update(r, c, value);
            }
        } else if (op == "MERGE") {
            int r1 = stoi(args[1]) - 1, c1 = stoi(args[2]) - 1;
            int r2 = stoi(args[3]) - 1, c2 = stoi(args[4]) - 1;
            merge(r1, c1, r2, c2);
        } else if (op == "UNMERGE") {
            int r = stoi(args[1]) - 1, c = stoi(args[2]) - 1;
            unmerge(r, c);
        } else if (op == "PRINT") {
            int r = stoi(args[1]) - 1, c = stoi(args[2]) - 1;
            string result = print(r, c);
            answer.push_back(result);
        }
    }
    
    return answer;
}
