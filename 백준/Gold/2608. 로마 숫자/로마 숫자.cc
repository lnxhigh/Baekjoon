#include <bits/stdc++.h>
using namespace std;

unordered_map<int,string> encodeMap;

unordered_map<string,int> decodeMap {
    {"I", 1}, {"II", 2}, {"III", 3}, {"IV", 4}, {"V", 5}, 
    {"VI", 6}, {"VII", 7}, {"VIII", 8}, {"IX", 9},
    
    {"X", 10}, {"XX", 20}, {"XXX", 30}, {"XL", 40}, {"L", 50}, 
    {"LX", 60}, {"LXX", 70}, {"LXXX", 80}, {"XC", 90},

    {"C", 100}, {"CC", 200}, {"CCC", 300}, {"CD", 400}, {"D", 500}, 
    {"DC", 600}, {"DCC", 700}, {"DCCC", 800}, {"CM", 900},

    {"M", 1000}, {"MM", 2000}, {"MMM", 3000},
};

unordered_map<string,int> all;

string encode(int num) {
    stack<string> st;
    int mul = 1;

    while (num) {
        int d = num % 10;
        if (num % 10 != 0) { st.push(encodeMap[mul*d]); }
        mul *= 10; num /= 10;
    }
    
    string res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    
    return res;
}

int main() {
    string A, B;
    cin >> A >> B;

    for (pair<string,int> p : decodeMap) {
        string rome = p.first;
        int num = p.second;
        encodeMap[num] = rome;
    }

    for (int i = 1; i < 4000; i++) {
        string rome = encode(i);
        all[rome] = i;
    }
    
    int res = all[A] + all[B];
    cout << res << '\n';
    cout << encode(res) << '\n';

    return 0;
}
