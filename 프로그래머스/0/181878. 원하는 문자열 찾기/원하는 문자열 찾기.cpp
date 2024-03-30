#include <string>
#include <vector>

using namespace std;

void tolower(string& str) {
    for (char& c : str) {
        c = tolower(c);   
    }
}

int solution(string myString, string pat) {
    tolower(myString);
    tolower(pat);
    int pos = myString.find(pat);
    int answer = (pos != string::npos);
    return answer;
}