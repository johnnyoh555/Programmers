// https://github.com/algorithm-haneun-42/algorithm?tab=readme-ov-file
#include <string>
#include <vector>
#include <queue>
using namespace std;
int d[10];

bool check(int a) {
    for (int i = a + 1; i < 10; i++)
        if (d[i]) return false;
    return true;
}

int solution(vector<int> p, int l) {
    int ans = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < p.size(); i++) {
        q.push({p[i], i});
        d[p[i]]++;
    }
    while (true) {
        if (check(q.front().first)) {
            ans++;
            d[q.front().first]--;
            if (q.front().second == l) break;
        } else {
            q.push(q.front());
        }
        q.pop();
    }
    return ans;
}