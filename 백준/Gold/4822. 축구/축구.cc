#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

string formatRank(int rank)
{
    switch (rank)
    {
    case 1:
        return "1st";
    case 2:
        return "2nd";
    case 3:
        return "3rd";
    }

    return to_string(rank) + "th";
}

void dfs(
    int idx, int maxIdx,
    vector<int> &scores, vector<pair<int, int>> &matches,
    vector<int> &lowRanks, vector<int> &highRanks)
{
    if (idx == maxIdx)
    {
        int num_teams = scores.size();

        for (int i = 0; i < num_teams; i++)
        {
            int rank = 1;

            // Naive search
            for (int j = 0; j < num_teams; j++)
            {
                if (scores[j] > scores[i])
                    rank++;
            }

            lowRanks[i] = max(lowRanks[i], rank);
            highRanks[i] = min(highRanks[i], rank);
        }

        return;
    }

    auto [x, y] = matches[idx];

    // Win
    scores[x] += 3;
    dfs(idx + 1, maxIdx, scores, matches, lowRanks, highRanks);
    scores[x] -= 3;

    // Draw
    scores[x]++, scores[y]++;
    dfs(idx + 1, maxIdx, scores, matches, lowRanks, highRanks);
    scores[x]--, scores[y]--;

    // Lose
    scores[y] += 3;
    dfs(idx + 1, maxIdx, scores, matches, lowRanks, highRanks);
    scores[y] -= 3;
}

int main()
{
    FastIO;

    while (true)
    {
        int n, m;
        cin >> n >> m;
        if (n == 0 || m == 0)
            break;

        vector<string> teams;
        map<string, int> teamIndexMap;
        vector<string> teamNameMap(n);

        for (int i = 0; i < n; i++)
        {
            string team;
            cin >> team;

            teams.emplace_back(team);
            teamIndexMap[team] = i;
            teamNameMap[i] = team;
        }

        vector<int> scores(n);
        vector<pair<int, int>> matches;
        vector<int> highRanks(n, n);
        vector<int> lowRanks(n, 0);

        for (int i = 0; i < m; i++)
        {
            string firstTeam, secondTeam, vs;
            int x, y;

            cin >> firstTeam >> vs >> secondTeam;
            cin >> x >> y;
            secondTeam.pop_back();

            int first = teamIndexMap[firstTeam];
            int second = teamIndexMap[secondTeam];

            if (x < 0 || y < 0)
            {
                matches.emplace_back(first, second);
            }
            else
            {
                if (x > y)
                {
                    scores[first] += 3;
                }
                else if (x < y)
                {
                    scores[second] += 3;
                }
                else
                {
                    scores[first]++;
                    scores[second]++;
                }
            }
        }

        // Brute force
        int num_matches = matches.size();
        dfs(0, num_matches, scores, matches, lowRanks, highRanks);

        for (int i = 0; i < n; i++)
        {
            string team = teamNameMap[i];
            cout << "Team " << team;
            cout << " can finish as high as ";
            cout << formatRank(highRanks[i]) << " place and as low as ";
            cout << formatRank(lowRanks[i]) << " place.";
            cout << "\n";
        }

        cout << "\n";
    }

    return 0;
}
