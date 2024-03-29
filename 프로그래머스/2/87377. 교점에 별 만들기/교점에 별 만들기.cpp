#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>

using namespace std;

bool check(vector<int> &lineA, vector<int> &lineB) {
    // Ax + By + C = 0
    long long A, B, E;
    long long C, D, F;
    
    A = lineA[0]; B = lineA[1]; E = lineA[2];
    C = lineB[0]; D = lineB[1]; F = lineB[2];
    
    long long det = A*D - B*C;
    
    if (det == 0) return false;
    if ((B*F-E*D) % det != 0) return false;
    if ((E*C-A*F) % det != 0) return false;
    
    return true;
}

pair<int,int> intersect(vector<int> &lineA, vector<int> &lineB) {
    // Ax + By + C = 0
    long long A, B, E;
    long long C, D, F;
    int x, y;
    
    A = lineA[0]; B = lineA[1]; E = lineA[2];
    C = lineB[0]; D = lineB[1]; F = lineB[2];
    
    long long det = A*D - B*C;
    
    x = (B*F-E*D) / det;
    y = (E*C-A*F) / det;
    
    return { x, y };
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    set<pair<int,int>> points;
    
    const int N = line.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!check(line[i], line[j])) continue;
            
            points.insert(intersect(line[i], line[j]));
        }
    }
    
    cout << points.size() << endl;
    for (pair<int,int> point : points) {
        cout << point.first << ' ' << point.second << '\n';
    }
    
    int width, height;
    int minX, maxX, minY, maxY;
    
    minX = maxX = (*points.begin()).first;
    minY = maxY = (*points.begin()).second;
    
    for (auto iter = points.begin(); iter != points.end(); iter++) {
        pair<int,int> point = *iter;
        minX = min(minX, point.first);
        maxX = max(maxX, point.first);
        minY = min(minY, point.second);
        maxY = max(maxY, point.second);
    }
    
    width = maxX - minX + 1;
    height = maxY - minY + 1;
    cout << width << ' ' << height << endl;
    
    for (int h = 0; h < height; h++) {
        string s = "";
        for (int w = 0; w < width; w++) {
            s += ".";   
        }
        answer.push_back(s);
    }
    
    for (auto iter = points.begin(); iter != points.end(); iter++) {
        pair<int,int> point = *iter;
        int w = point.first - minX;
        int h = maxY - point.second;
        answer[h].replace(w, 1, "*");
    }
    
    return answer;
}