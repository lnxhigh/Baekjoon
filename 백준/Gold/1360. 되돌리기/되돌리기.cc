#include <bits/stdc++.h>
using namespace std;

int n;
stack<tuple<string, int, int>> st;

void input()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string cmd;
        int x, t;

        cin >> cmd;

        if (cmd == "type")
        {
            char alpha;
            cin >> alpha >> t;
            x = (int)alpha;
        }
        else if (cmd == "undo")
        {
            cin >> x >> t;
        }

        st.push({cmd, x, t});
    }
}

void solve()
{
    stack<int> ans;

    while (!st.empty())
    {
        auto [cmd, x, t] = st.top();
        st.pop();

        if (cmd == "type")
        {
            ans.push(x);
        }
        else if (cmd == "undo")
        {
            while (!st.empty())
            {
                auto [_, __, s] = st.top();
                if (s < t - x)
                    break;

                st.pop();
            }
        }
    }

    while (!ans.empty())
    {
        char alpha = (char)ans.top();
        ans.pop();
        cout << alpha;
    }
    cout << '\n';
}

int main()
{
    input();
    solve();
}
