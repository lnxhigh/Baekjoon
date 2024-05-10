#include <bits/stdc++.h>
using namespace std;

bool parser(string str)
{
    string newStr;

    for (char c : str)
    {
        if (c == '+') newStr += " + ";
        else if (c == '-') newStr += " - ";
        else if (c >= '0' && c <= '9') newStr += c;
        else if (c == ' ') continue;
    }
    
    std::stringstream ss(newStr);
    int result = 0;
    string number;
    char op;

    ss >> number;
    result += stoi(number);

    while (ss >> op >> number) {
        if (op == '+') {
            result += stoi(number);
        } else if (op == '-') {
            result -= stoi(number);
        }
        else
        {
            std::cerr << "Wrong operator: " << op << '\n';
        }
    }
    
    return (result == 0);
}

void backTrack(int N, vector<char> &operators)
{
    if (operators.size() == N-1)
    {
        string str = "1";
        for (int i = 0; i < N-1; i++)
        {
            str += operators[i];
            str += to_string(i+2);
        }

        if (parser(str)) cout << str << '\n';
        return;
    }

    for (char c : {' ', '+', '-'})
    {
        operators.push_back(c);
        backTrack(N, operators);
        operators.pop_back();
    }
}

void solve(int N)
{
    vector<char> op;
    backTrack(N, op);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N;
        cin >> N;
        solve(N);
        cout << '\n';
    }

    return 0;
}