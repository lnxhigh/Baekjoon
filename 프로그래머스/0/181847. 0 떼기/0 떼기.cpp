#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    int pos = 0;
    for (char c : n_str) {
        if (c != '0') break;
        pos++;
    }
    n_str.erase(0, pos);
    return n_str;
}