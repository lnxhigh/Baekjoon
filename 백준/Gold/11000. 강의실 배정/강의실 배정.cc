#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 1 << 18;
pair<int,int> course[MAX];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++) {
        int S, E;
        cin >> S >> E;
        course[i] = { S, E };
    }
    
    sort(course, course + N);

    int res = 0;
    for (int i = 0; i < N; i++) {
        int S = course[i].first, E = course[i].second;
        
        // If the remaining minimum end time is less than or equal to start time of current course,
        // that information is no longer useful because we sorted courses by start time
        // This logic is similar to problems using stack, if I can get the currect answer ...
        while (!pq.empty() && pq.top() <= S) pq.pop();

        // push current one that can be processed later
        pq.push(E);

        // pq.size() means there are pq.size() duplicated courses
        res = max(res, (int) pq.size());
    }

    cout << res << '\n';
    return 0;
}
