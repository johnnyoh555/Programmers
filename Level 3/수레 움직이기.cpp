#include <string>
#include <vector>

using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> b;
int ans = 2e9, n, m;
bool rvis[4][4];
bool bvis[4][4];

void dfs(int ry, int rx, int by, int bx, int dep) {
    if (b[ry][rx] == 3 && b[by][bx] == 4) {if(dep < ans) ans = dep; return;}
    for (int dir1 = 0; dir1 < 4; dir1++) {
        int nrx, nry;
        if (b[ry][rx] != 3) {
            nrx = rx + dx[dir1];
            nry = ry + dy[dir1];
            if (nrx < 0 || nrx >= m || nry < 0 || nry >= n) continue;
            if (b[nry][nrx] == 5 || rvis[nry][nrx]) continue;
            rvis[nry][nrx] = 1;
        } else {
            nrx = rx; nry = ry;
        }
        for (int dir2 = 0; dir2 < 4; dir2++) {
            int nbx, nby;
            if (b[by][bx] != 4) {
                nbx = bx + dx[dir2];
                nby = by + dy[dir2];
                if (nbx < 0 || nbx >= m || nby < 0 || nby >= n) continue;
                if (b[nby][nbx] == 5 || bvis[nby][nbx] || (nby == nry && nbx == nrx)) continue;
                if (nry == by && nrx == bx && nby == ry && nbx == rx) continue;
                bvis[nby][nbx] = 1;
            } else {
                nbx = bx; nby = by;
                if (nby == nry && nbx == nrx) continue;
            }
            dfs(nry, nrx, nby, nbx, dep + 1);
            if (b[by][bx] == 4) break;
            bvis[nby][nbx] = 0;
        }
        if (b[ry][rx] == 3) break;
        rvis[nry][nrx] = 0;
    }
}

int solution(vector<vector<int>> maze) {
    b = maze;
    n = maze.size();
    m = maze[0].size();
    int ry, rx, by, bx;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 1) {ry = i; rx = j;}
            if (maze[i][j] == 2) {by = i; bx = j;}
        }
    }
    rvis[ry][rx] = 1;
    bvis[by][bx] = 1;
    dfs(ry, rx, by, bx, 0);
    if (ans == 2e9) ans = 0;
    return ans;
}