#include <bits/stdc++.h>
using namespace std;

int n;
int n_walls;
bool walls[32][32];
int day;

// 좌 하 우 상
int dx[5] = {0, 0, +1, 0, -1};
int dy[5] = {0, -1, 0, +1, 0};

int getDir(char x)
{
    switch (x)
    {
    case 'S':
        return 0;
    case 'L':
        return 1;
    case 'D':
        return 2;
    case 'R':
        return 3;
    case 'U':
        return 4;
    }

    return 0;
}

class Player
{
public:
    int x = 0;
    int y = 0;
    string ops = "";
    int index = 0;

    bool hasDied = false;
    int diedAt = 0;

    Player(int _x, int _y, string _ops)
        : x(_x), y(_y), ops(_ops) {}

    void move()
    {
        char charDir = ops[index++];
        int dir = getDir(charDir);

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
        {
            return;
        }
        else if (walls[nx][ny])
        {
            return;
        }

        x = nx;
        y = ny;
    }

    void die(int t)
    {
        hasDied = true;
        diedAt = t;
    }
};

class Zombie
{
public:
    int x = 0;
    int y = 0;
    int dir = 0;
    int speed = 0;

public:
    Zombie(int _x, int _y, int _dir, int _speed)
        : x(_x), y(_y), dir(_dir), speed(_speed) {}

    virtual void move() = 0;
};

class LowZombie : public Zombie
{
public:
    LowZombie(int _x, int _y, int _dir, int _speed)
        : Zombie(_x, _y, _dir, _speed) {}

    void flipDir()
    {
        dir = ((dir + 1) % 4) + 1;
    }

    void move()
    {
        int cnt = speed;

        while (cnt > 0)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            bool stop = (nx < 0 || nx >= n || ny < 0 || ny >= n);
            if (stop)
                break;

            stop |= walls[nx][ny];
            if (stop)
                break;

            // Move
            cnt--;
            x = nx;
            y = ny;
        }

        if (cnt > 0)
            flipDir();
    }
};

class HighZombie : public Zombie
{
public:
    HighZombie(int _x, int _y, int _dir, int _speed)
        : Zombie(_x, _y, _dir, _speed) {}
    void move()
    {
        int cnt = speed;

        while (cnt > 0)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            bool stop = (nx < 0 || nx >= n || ny < 0 || ny >= n);
            if (stop)
                break;

            stop |= walls[nx][ny];
            if (stop)
            {
                // 벽 부수기
                if (cnt > 0)
                {
                    walls[nx][ny] = false;
                }

                break;
            }

            // Move
            cnt--;
            x = nx;
            y = ny;
        }

        changeDir();
    }

    int countWalls(int d)
    {
        int cnt = 0;
        int nx = x;
        int ny = y;

        while (nx >= 0 && nx < n && ny >= 0 && ny < n)
        {
            cnt += walls[nx][ny];
            nx += dx[d];
            ny += dy[d];
        }

        return cnt;
    }

    void changeDir()
    {
        int maxCnt = 0;
        int nextDir = 0;

        for (int d = 1; d <= 4; d++)
        {
            int cnt = countWalls(d);
            if (cnt >= maxCnt)
            {
                maxCnt = cnt;
                nextDir = d;
            }
        }

        dir = nextDir;
    }
};

Player *player;
int n_zombies;
vector<Zombie *> zombies;

void input()
{
    // Game
    cin >> n;

    // Player

    string ops;
    cin >> ops;

    int px, py;
    cin >> px >> py;
    --px, --py;

    player = new Player(px, py, ops);

    // Walls

    cin >> n_walls;
    for (int i = 0; i < n_walls; i++)
    {
        int wx, wy;
        cin >> wx >> wy;
        --wx, --wy;
        walls[wx][wy] = true;
    }

    // Zombies

    cin >> n_zombies;
    for (int i = 0; i < n_zombies; i++)
    {
        int zx, zy, type, dir, speed;
        char charDir;

        cin >> zx >> zy >> type >> charDir >> speed;
        --zx, --zy;
        dir = getDir(charDir);

        Zombie *zombie;

        switch (type)
        {
        case 0:
            zombie = new LowZombie(zx, zy, dir, speed);
            break;

        case 1:
            zombie = new HighZombie(zx, zy, dir, speed);
            break;
        }

        zombies.emplace_back(zombie);
    }

    // Day

    cin >> day;
}

void debug()
{
    char arr[32][32];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = walls[i][j] ? '*' : '.';
        }
    }

    arr[player->x][player->y] = 'P';

    for (Zombie *z : zombies)
    {
        arr[z->x][z->y] = 'Z';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "=======================================\n";
}

void solve()
{
    bool gameover = false;

    for (int t = 1; t <= day && !gameover; t++)
    {
        player->move();

        for (Zombie *zombie : zombies)
        {
            zombie->move();

            bool chk = (zombie->x == player->x) && (zombie->y == player->y);
            gameover |= chk;

            if (gameover)
            {
                player->die(t);
                break;
            }
        }
    }

    if (gameover)
    {
        int t = player->diedAt;
        cout << t << '\n';
        cout << "DEAD..." << '\n';
    }
    else
    {
        cout << "ALIVE!" << '\n';
    }
}

main()
{
    input();
    solve();

    return 0;
}
