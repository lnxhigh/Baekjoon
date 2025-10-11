#include <bits/stdc++.h>
using namespace std;

int r, c;
string arr[64];

int dx[4] = {-1, 0, +1, 0};
int dy[4] = {0, -1, 0, +1};

int sx, sy;
int fx, fy;

int src[64][64];
int dst[64][64];
bool opt[64][64][4];

void bfs(int x, int y, int target[64][64])
{
    deque<tuple<int, int, int>> dq;
    bool vis[64][64];
    memset(vis, false, sizeof(vis));

    dq.push_front({x, y, 0});
    vis[x][y] = true;

    while (!dq.empty())
    {
        auto [x, y, t] = dq.front();
        dq.pop_front();
        target[x][y] = t;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            else if (vis[nx][ny])
                continue;

            if (arr[nx][ny] == 'g')
            {
                dq.push_back({nx, ny, t + 1});
            }
            else
            {
                dq.push_front({nx, ny, t});
            }

            vis[nx][ny] = true;
        }
    }
}

void input()
{
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        cin >> arr[i];
    }
}

void init()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == 'S')
            {
                sx = i, sy = j;
                bfs(i, j, src);
            }
            if (arr[i][j] == 'F')
            {
                fx = i, fy = j;
                bfs(i, j, dst);
            }
        }
    }
}

void findMinimumTrashPath()
{
    for (int x = 0; x < r; x++)
    {
        for (int y = 0; y < c; y++)
        {
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                {
                    continue;
                }

                opt[x][y][dir] = (src[x][y] + dst[nx][ny] == src[fx][fy]);
            }
        }
    }
}

bool isNearTrash(int x, int y)
{
    if (arr[x][y] != '.')
        return false;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= r || ny < 0 || ny >= c)
            continue;

        if (arr[nx][ny] == 'g')
            return true;
    }

    return false;
}

pair<int, int> solve()
{
    deque<tuple<int, int, int>> dq;
    bool vis[64][64];
    memset(vis, false, sizeof(vis));

    dq.push_front({sx, sy, 0});
    vis[sx][sy] = true;

    while (!dq.empty())
    {
        auto [x, y, t] = dq.front();
        dq.pop_front();

        if (arr[x][y] == 'F')
        {
            return {src[fx][fy], t};
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            else if (!opt[x][y][i] || vis[nx][ny])
                continue;

            if (isNearTrash(nx, ny))
            {
                dq.push_back({nx, ny, t + 1});
            }
            else
            {
                dq.push_front({nx, ny, t});
            }

            vis[nx][ny] = true;
        }
    }

    return {0, 0};
}

int main()
{
    input();
    init();

    // 지나가는 쓰레기 최소화
    findMinimumTrashPath();

    // 지나가는 쓰레기 옆 최소화
    auto [a, b] = solve();
    cout << a << ' ' << b << '\n';

    return 0;
}
