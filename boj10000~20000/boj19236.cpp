#include <cstdio>
#include <algorithm>

using namespace std;


struct FISH
{
    int y, x, dir;
    bool isdead;
};

const int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

void cpmap(int dest[4][4], int src[4][4])
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            dest[i][j] = src[i][j];
    return;
}

void cpfish(FISH dest[17], FISH src[17])
{
    for (int i = 0; i <= 16; ++i)
        dest[i] = src[i];
}

int dfs(int origin_map[][4], int y, int x, int dir, FISH origin_fish[17])
{

    int map[4][4];
    FISH fish[17];
    cpmap(map, origin_map);
    cpfish(fish, origin_fish);
    int eat = map[y][x];
    dir = fish[map[y][x]].dir;

    fish[map[y][x]].x = -1;

    fish[map[y][x]].y = -1;
    fish[map[y][x]].isdead = true;
    map[y][x] = 0;

    int ans = 0;

    for (int i = 1; i <= 16; ++i)
    {
        if (fish[i].isdead == false)
        {

            int nx = fish[i].x, ny = fish[i].y;
            for (int d = 0; d <= 7; ++d)
            {
                int cx = fish[i].x + dx[fish[i].dir];
                int cy = fish[i].y + dy[fish[i].dir];

                if (cx == x && cy == y)
                {
                    fish[i].dir = (fish[i].dir + 1) % 8;
                    continue;
                }
                if (cx < 0 || cy < 0 || cx >= 4 || cy >= 4)
                {
                    fish[i].dir = (fish[i].dir + 1) % 8;
                    continue;
                }

                nx = cx;
                ny = cy;
                break;
            }

            if (map[ny][nx] == 0)
            {
                map[fish[i].y][fish[i].x] = 0;
                map[ny][nx] = i;
                fish[i].y = ny;
                fish[i].x = nx;
            }
            else
            {
                int tx, ty, temp;
                tx = fish[i].x;
                ty = fish[i].y;
                fish[i].x = nx;
                fish[i].y = ny;
                fish[map[ny][nx]].x = tx;
                fish[map[ny][nx]].y = ty;

                map[ty][tx] = map[ny][nx];
                map[ny][nx] = i;
            }
        }
    }

    int cy = y + dy[dir];
    int cx = x + dx[dir];

    while (!(cy < 0 || cx < 0 || cy >= 4 || cx >= 4))
    {
        if (map[cy][cx] != 0)
            ans = max(ans, dfs(map, cy, cx, dir, fish));
        cy += dy[dir];
        cx += dx[dir];
    }
    return ans + eat;
}

int main()
{
    int map[4][4] = {0};
    FISH fish[17];
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            int l, d;
            scanf("%d %d", &l, &d);
            fish[l].y = i;
            fish[l].x = j;
            fish[l].isdead = false;
            fish[l].dir = d - 1;
            map[i][j] = l;
        }

    printf("%d", dfs(map, 0, 0, 0, fish));

    return 0;
}