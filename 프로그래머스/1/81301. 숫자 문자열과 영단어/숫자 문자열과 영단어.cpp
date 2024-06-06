#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string table[10] = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"                   
    };
    
    string res = "";   
    int size = s.size();
    
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < 10; k++) {
            int m = table[k].size();
            if (s[i] >= '0' && s[i] <= '9') {
                res += s[i];
                break;
            }
            else if (i < size - m + 1 && s.substr(i, m) == table[k]) {
                res += to_string(k);
                break;
            }
        }
    }
    
    int answer = stoi(res);
    return answer;
}