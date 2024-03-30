#include <string>
#include <vector>

using namespace std;

int add(int a, int b) {
    string x = to_string(a);
    string y = to_string(b);
    return stoi(x + y);
}

int solution(int a, int b) {
    int x = add(a, b);
    int y = add(b, a);
    return x >= y ? x : y ;
}