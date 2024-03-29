#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

pair<int,int> loc[10] = {
    { +2, 0 },
    { -1, -1 }, { -1, 0 }, { -1, +1 },
    {  0, -1 }, {  0, 0 }, {  0, +1 },
    { +1, -1 }, { +1, 0 }, { +1, +1 }
};

int dist(pair<int,int> from, pair<int,int> to) {
    int dx = from.first - to.first;
    int dy = from.second - to.second;
    return abs(dx) + abs(dy);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int,int> leftPos  = { +2, -1 };
    pair<int,int> rightPos = { +2, +1 };
    
    for (int num : numbers) {
        string dir;
        
        if (num == 1 || num == 4 || num == 7) {
            leftPos = loc[num];
            dir = "L";
        }
        else if (num == 3 || num == 6 || num == 9) {
            rightPos = loc[num];
            dir = "R";
        }
        else {
            int ld = dist(leftPos, loc[num]);
            int rd = dist(rightPos, loc[num]);
            if (ld < rd) {
                dir = "L";
                leftPos = loc[num];
            }
            else if (ld > rd) {
                dir = "R";
                rightPos = loc[num];
            }
            else {
                if (hand == "left") {
                    dir = "L";
                    leftPos = loc[num];
                }
                else if (hand == "right") {
                    dir = "R";
                    rightPos = loc[num];
                }
            }
        }
        
        answer += dir;
    }
    
    return answer;
}