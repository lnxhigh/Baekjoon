#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string table[10] = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"                   
    };
    
    int answer = 0;
    int size = s.size();
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < 10; k++) {
            if (i < size - 3 + 1 && s.substr(i, 3) == table[k].substr(0, 3)) {
                answer = answer * 10 + k;
                break;
            }
            else if (s.substr(i,1) == to_string(k)) {
                answer = answer * 10 + k;
                break;
            } 
        }
    }
    return answer;
}