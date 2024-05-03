// https://school.programmers.co.kr/learn/courses/30/lessons/159993
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int bfs(vector<string>& maps, int sx, int sy) {
    int n = maps.size();
    int m = maps[0].size();
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<pair<int, int> > q;
    int vis[n][m];
    memset(vis, 0, sizeof(vis));
    q.push({sy, sx});
    vis[sy][sx] = 1;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (maps[cur.first][cur.second] == 'L') return vis[cur.first][cur.second] - 1;
        for (int dir = 0; dir < 4; dir++) {
            int nx = dx[dir] + cur.second;
            int ny = dy[dir] + cur.first;
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (vis[ny][nx] || maps[ny][nx] == 'X') continue;
            vis[ny][nx] = vis[cur.first][cur.second] + 1;
            q.push({ny, nx});
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    int sx, sy, ex, ey, n, m, a, b;
    n = maps.size();
    m = maps[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maps[i][j] == 'S') {sy = i; sx = j;}
            if (maps[i][j] == 'E') {ey = i; ex = j;}
        }
    }
    a = bfs(maps, sx, sy);
    b = bfs(maps, ex, ey);
    if (a == -1 || b == -1) answer = -1;
    else answer = a + b;
    return answer;
}