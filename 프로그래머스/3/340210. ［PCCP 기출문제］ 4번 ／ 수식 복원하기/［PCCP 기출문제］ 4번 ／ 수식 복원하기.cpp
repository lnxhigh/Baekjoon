#include <bits/stdc++.h>

using namespace std;

string plus_op(string x, string y, int digit) {
    int first[128] = { 0 };
    int second[128] = { 0 };
    int result[128] = { 0 };
    
    // Init
    
    for (int i = 0; i < x.size(); i++) {
        int index = x.size() - i - 1;
        first[i] = x[index] - '0';
    }
    
    for (int i = 0; i < y.size(); i++) {
        int index = y.size() - i - 1;
        second[i] = y[index] - '0';
    }
    
    // Sum
    
    int m = max(x.size(), y.size());
    
    for (int i = 0; i < m; i++) {
        int sum = first[i] + second[i] + result[i];
        
        if (sum < digit) {
            result[i] = sum;
        } else {
            result[i] = sum - digit;
            result[i + 1]++;
        }
    }
    
    // Result
    
    string str = "";
    
    for (int i = 128 - 1; i >= 0; i--) {
        str.push_back(result[i] + '0');
    }
    
    int zero = 0;
    while (zero < 128 && str[zero] == '0') {
        zero++;
    }
    
    if (zero >= 128) return "0";
    
    return str.substr(zero);
}

string minus_op(string x, string y, int digit) {
    int first[128] = { 0 };
    int second[128] = { 0 };
    int result[128] = { 0 };
    
    // Init
    
    for (int i = 0; i < x.size(); i++) {
        int index = x.size() - i - 1;
        first[i] = x[index] - '0';
    }
    
    for (int i = 0; i < y.size(); i++) {
        int index = y.size() - i - 1;
        second[i] = y[index] - '0';
    }
    
    // Minus
    
    int m = max(x.size(), y.size());
    
    for (int i = 0; i < m; i++) {
        int diff = first[i] - second[i];
        
        if (diff >= 0) {
            result[i] = diff;
        } else {
            first[i + 1]--;
            result[i] = diff + digit;
        }
    }
    
    // Result
    
    string str = "";
    
    for (int i = 128 - 1; i >= 0; i--) {
        str.push_back(result[i] + '0');
    }
    
    int zero = 0;
    while (zero < 128 && str[zero] == '0') {
        zero++;
    }
    
    if (zero >= 128) return "0";
    
    return str.substr(zero);
}

tuple<string,char,string, string> parse(const string &expression) {    
    int op_idx = expression.find_last_of("+-");
    int eq_idx = expression.find('=');
    
    string x = expression.substr(0, op_idx - 1);
    char op = expression[op_idx];
    string y = expression.substr(op_idx + 2, (eq_idx - 1) - (op_idx + 2));
    string right = expression.substr(eq_idx + 2);
    
    return { x, op, y, right };
}

bool check(const vector<string> &expressions, int digit) {
    for (const string& expression : expressions) {
        auto [x, op, y, right] = parse(expression);
        
        // 사용되는 숫자 범위 체크
        for (char c : x) {
            int t = c - '0';
            if (t >= digit) return false;
        }
        for (char c : y) {
            int t = c - '0';
            if (t >= digit) return false;
        }
        for (char c : right) {
            if (c == 'X') continue;
            int t = c - '0';
            if (t >= digit) return false;
        }
        
        if (right == "X") continue;
        
        string value = (op == '+') ? plus_op(x, y, digit) : minus_op(x, y, digit);
        if (value != right) return false;
    }
    
    return true;
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    
    // Find digits
    
    vector<int> digits;
    
    for (int digit = 2; digit < 10; digit++) {
        bool chk = check(expressions, digit);
        if (!chk) continue;
        
        digits.push_back(digit);
    }
    
    // Now generate answer

    for (const string& expression : expressions) {
        auto [x, op, y, right] = parse(expression);
        if (right != "X") continue;
        
        set<string> values;
        
        for (int digit : digits) {
            string value = (op == '+') 
                ? plus_op(x, y, digit) 
                : minus_op(x, y, digit);
            
            values.insert(value);
        }
        
        string fill = (values.size() <= 1) ? *values.begin() : "?";
        string message = x + " " + op + " " + y + " = " + fill;
        answer.push_back(message);
    }
    
    return answer;
}
