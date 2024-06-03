#include <bits/stdc++.h>
using namespace std;

int N;
unordered_map<string,string> t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    t["CU"] = "see you";
    t[":-)"] = "I’m happy";
    t[":-("] = "I’m unhappy";
    t[";-)"] = "wink";
    t[":-P"] = "stick out my tongue";
    t["(~.~)"] = "sleepy";
    t["TA"] = "totally awesome";
    t["CCC"] = "Canadian Computing Competition";
    t["CUZ"] = "because";
    t["TY"] = "thank-you";
    t["YW"] = "you’re welcome";
    t["TTYL"] = "talk to you later";

    while (true) {
        string shortForm;
        cin >> shortForm;
        
        string message = t.count(shortForm) ? t[shortForm] : shortForm;
        cout << message << '\n';

        if (shortForm == "TTYL") break;
    }

    return 0;
}
