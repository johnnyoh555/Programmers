// https://school.programmers.co.kr/learn/courses/30/lessons/42860
#include <string>
#include <vector>
#include <cmath>

using namespace std;
string  nn;
int     mn = 2e9;

void dfs(string& str, int idx, int cnt) {
    cnt += min(nn[idx] - 'A', 'Z' - nn[idx] + 1);
    str[idx] = nn[idx];
    if (str == nn) {
        if (cnt < mn) mn = cnt;
    } else {
        int a = 0, b = 0, tmp1 = idx, tmp2 = idx;
        while (str[tmp1] == nn[tmp1]) {tmp1--; a++; if (tmp1 < 0) tmp1 = nn.size() - 1;}
        while (str[tmp2] == nn[tmp2]) {tmp2++; b++; if (tmp2 == nn.size()) tmp2 = 0;}
        dfs(str, tmp1, cnt + a);
        dfs(str, tmp2, cnt + b);
    }
    str[idx] = 'A';
}

int solution(string name) {
    string str;
    nn = name;
    for (int i = 0; i < name.size(); i++) str.push_back('A');
    dfs(str, 0, 0);
    return mn;
}