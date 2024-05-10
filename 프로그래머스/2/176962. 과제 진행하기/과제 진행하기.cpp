#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    sort(plans.begin(), plans.end(),
        [](vector<string> &left, vector<string> &right) {
             return left[1] < right[1];
         }
    );
    
    string currentPlan = "";
    unordered_map<string, int> playTime;
    unordered_map<int, string> planToStart;
    
    for (vector<string> plan : plans)
    {
        string name = plan[0];
        string startTimeStr = plan[1];
        string playTimeStr = plan[2];
        
        int hour = stoi(startTimeStr.substr(0,2));
        int minute = stoi(startTimeStr.substr(3,2));
        
        playTime[name] = stoi(playTimeStr);
        planToStart[hour*60+minute] = name;
    }
    
    stack<string> notCompletedPlan;
    
    for (int t = 0; t < 1000000; t++)
    {
        if (answer.size() == plans.size()) break;
        
        if (!notCompletedPlan.empty())
        {
            playTime[notCompletedPlan.top()]--;
            
            if (playTime[notCompletedPlan.top()] <= 0)
            {
                cout << notCompletedPlan.top() << ": " << t << '\n';
                answer.push_back(notCompletedPlan.top());
                notCompletedPlan.pop();
            }
        }
                
        if (planToStart.count(t) > 0)
        {
            notCompletedPlan.push(planToStart[t]);
        }
    }
    
    return answer;
}