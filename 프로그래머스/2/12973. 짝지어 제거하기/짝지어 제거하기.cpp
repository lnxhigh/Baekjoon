#include <bits/stdc++.h>
using namespace std;

int solution(string word)
{
    stack<char> st;
    
    for (char alphabet : word) {
        char top;
        if (st.empty() || st.top() != alphabet) st.push(alphabet);
        else st.pop();
    }
    
    if (st.empty()) return 1;
    
    return 0;
}