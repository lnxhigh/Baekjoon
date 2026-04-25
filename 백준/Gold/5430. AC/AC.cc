#include <iostream>
#include <deque>
#include <sstream>
#include <algorithm>
using namespace std;

deque<int> split(string input, char delimiter) {
    deque<int> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(stoi(temp));
    }
    
    return answer;
}

void f(string p, int n, deque<int> d) {
    bool rev = false;
    int front = 0, back = 0;

    for (char c : p) {
        if (c == 'R') {
            rev = !rev;
        }
        else if (c == 'D') {
            if (rev) back++;
            else front++;
        }
    }

    if (front + back > n) {
        cout << "error" << endl;
        return;
    }

    for (int i = 0; i < front; i++) {
        d.pop_front();
    }
    for (int i = 0; i < back; i++) {
        d.pop_back();
    }
    if (rev) {
        reverse(d.begin(), d.end());
    }

    cout << "[";
    if (d.empty()) {
        cout << "]" << endl;
        return;
    }
    
    int last = d.back();
    d.pop_back();
    
    for (int i : d) {
        cout << to_string(i) << ",";
    }
    cout << last << "]" << endl;

    return;
}

int main(void) {
    int T;
    string p;
    int n;
    string list;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> p;
        cin >> n;
        cin >> list;

        list = list.substr(1, list.size()-2);
        deque<int> d = split(list, ',');

        f(p, n, d);
    }

    return 0;
}