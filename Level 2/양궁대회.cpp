// https://school.programmers.co.kr/learn/courses/30/lessons/92342
#include <string>
#include <vector>

using namespace std;
int Ascore, nn, mx;
vector<int> apeach;
vector<int> tmp(11);
vector<int> answer = {-1};

bool cmp() {
    for (int i = 10; i >= 0; i--) {
        if (tmp[i] > answer[i]) return 1;
        else if (tmp[i] < answer[i]) return 0;
    }
}

void dfs(int dep, int arrow, int sum) {
    if (dep == 10 || arrow == 0) {
        tmp[10] = arrow;
        if (Ascore < sum && (mx < sum - Ascore || mx == sum - Ascore && cmp())) {mx = sum - Ascore; answer = tmp;}
        return;
    }
    if (apeach[dep] < arrow) {
        tmp[dep] = apeach[dep] + 1;
        if (apeach[dep]) Ascore -= 10 - dep;
        dfs(dep + 1, arrow - tmp[dep], sum + 10 - dep);
        if (apeach[dep]) Ascore += 10 - dep;
        tmp[dep] = 0;
    }
    dfs(dep + 1, arrow, sum);
}

vector<int> solution(int n, vector<int> info) {
    for (int i = 0; i < info.size(); i++) {if (info[i]) Ascore += (10 - i);}
    apeach = info;
    dfs(0, n, 0);
    return answer;
}