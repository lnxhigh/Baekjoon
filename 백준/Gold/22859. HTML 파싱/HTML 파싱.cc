#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int n;
string document;
bool space = false;

int main() {
    FastIO
    
    getline(cin, document);
    n = document.size();

    int ptr = 0;

    while (ptr < n) {
        string str;
        bool flag = (document[ptr] == '<');
        if (flag) ptr++;

        while (ptr < n) {
            char c = document[ptr];
            if (c == '<') {
                break;
            }
            else if (c == '>') {
                ptr++;
                break;
            }
            
            str.push_back(c);
            ptr++;
        }

        if (flag) {
            if (str.substr(0, 3) == "div") {
                if (str.size() > 5u && str.substr(4, 5) == "title") {
                    string title = str.substr(11);
                    title.pop_back();
                    cout << "title : " << title << '\n';
                }
            }
            else if (str == "/p") {
                cout << '\n';
                space = false;
            }
        }
        else {
            for (char c : str) {
                if (c == ' ') {
                    space = true;
                }
                else {
                    if (space) {
                        cout << ' ';
                        space = false;
                    }
                    cout << c;
                }
            }
        }
    }

    return 0;
}
