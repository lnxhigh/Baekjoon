#include <bits/stdc++.h>

using namespace std;

string solution(string myString) {
    for_each(myString.begin(), myString.end(), [] (char &c) {
        c = toupper(c);
    });
    
    return myString;
}