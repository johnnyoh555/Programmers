// https://school.programmers.co.kr/learn/courses/30/lessons/148653
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int storey) {
    long mn = 2e9;
    queue<pair<int,int>> q;
    q.push({storey, 0});
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        int a = cur.first % 10;
        cur.first /= 10;
        if (cur.first == 0) {
            if (11 - a < a) a = 11 - a;
            if (a + cur.second < mn) mn = cur.second + a;
            continue;
        }
        q.push({cur.first + 1, cur.second + 10 - a});
        q.push({cur.first, cur.second + a});
    }
    return mn;
}