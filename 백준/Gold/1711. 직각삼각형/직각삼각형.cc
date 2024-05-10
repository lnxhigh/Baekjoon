#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using Point = pair<long long int,long long int>;

int N;
vector<Point> points;

bool isRightTriangle(Point A, Point B, Point C)
{
    long long int x = (A.X - B.X) * (A.X - B.X) + (A.Y - B.Y) * (A.Y - B.Y);
    long long int y = (B.X - C.X) * (B.X - C.X) + (B.Y - C.Y) * (B.Y - C.Y);
    long long int z = (C.X - A.X) * (C.X - A.X) + (C.Y - A.Y) * (C.Y - A.Y);

    return (x == y + z || y == x + z || z == x + y);
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        long long int x, y;
        cin >> x >> y;
        Point point = { x, y };
        points.push_back(point);
    }

    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            for (int k = j+1; k < N; k++)
            {
                if (isRightTriangle(points[i], points[j], points[k]))
                {
                    cnt++;
                }
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}