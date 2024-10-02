#include <bits/stdc++.h>
using namespace std;

string FizzBuzz(int x) {
    if (x % 3 == 0 && x % 5 == 0) return "FizzBuzz";
    else if (x % 3 == 0) return "Fizz";
    else if (x % 5 == 0) return "Buzz";
    return to_string(x);
}

int main() {
    vector<string> S(3);
    for (string &x : S) cin >> x;

    int num = -1;
    for (int i = 0; i < 3; i++) {
        if (!isdigit(S[i][0])) continue;
        num = stoi(S[i]) + (3 - i);
        break;
    }

    cout << FizzBuzz(num) << '\n';
    return 0;
}
