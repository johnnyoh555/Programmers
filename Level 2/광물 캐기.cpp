// https://school.programmers.co.kr/learn/courses/30/lessons/172927
#include <string>
#include <vector>

using namespace std;
vector<int> p;
vector<string> m;
int ans = 2e9;

void dfs(int idx, int sum) {
    if (idx >= m.size() || (!p[0] && !p[1] && !p[2])) {
        if (sum < ans) ans = sum; return;   
    }
    if (p[0]) {
        int tmp = 0;
        for (int i = idx; i < idx + 5 && i < m.size(); i++) tmp += 1;
        p[0]--;
        dfs(idx + 5, sum + tmp);
        p[0]++;
    }
    if (p[1]) {
        int tmp = 0;
        for (int i = idx; i < idx + 5 && i < m.size(); i++) {
            if (m[i] == "diamond") tmp += 5;
            else tmp += 1;
        }
        p[1]--;
        dfs(idx + 5, sum + tmp);
        p[1]++;
    }
    if (p[2]) {
        int tmp = 0;
        for (int i = idx; i < idx + 5 && i < m.size(); i++) {
            if (m[i] == "diamond") tmp += 25;
            else if (m[i] == "iron") tmp += 5;
            else tmp += 1;
        }
        p[2]--;
        dfs(idx + 5, sum + tmp);
        p[2]++;
    }
}

int solution(vector<int> picks, vector<string> minerals) {\
    p = picks;
    m = minerals;
    dfs(0, 0);
    return ans;
}