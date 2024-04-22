#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int arr[501];
queue<pair<int, int> > q;
bool vis[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solution(vector<vector<int>> land) {
    int n = land.size();
    int m = land[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int mx = -1, mn = 501, cnt = 0;
             if (land[i][j] && !vis[i][j]) {
                 q.push({i, j});
                 vis[i][j] = 1; cnt++;
                 while (!q.empty()) {
                     pair<int, int> cur = q.front(); q.pop();
                     if (cur.second > mx) mx = cur.second;
                     if (cur.second < mn) mn = cur.second;
                     for (int dir = 0; dir < 4; dir++) {
                         int nx = dx[dir] + cur.second;
                         int ny = dy[dir] + cur.first;
                         if (nx < 0 || ny < 0 || nx >= land[i].size() || ny >= n) continue;
                         if (vis[ny][nx] || !land[ny][nx]) continue;
                         vis[ny][nx] = 1; cnt++;
                         if (nx > mx) mx = nx;
                         if (nx < mn) mn = nx;
                         q.push({ny, nx});
                     }
                 }
                 for (int i = mn; i <= mx; i++) arr[i] += cnt;
             }
        }
    }
    int mx = 0;
    for (int i = 0; i < m; i++) if (arr[i] > mx) {mx = arr[i];}
    return mx;
}