// https://school.programmers.co.kr/learn/courses/30/lessons/42890
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;
vector<vector<string>> rel;
vector<vector<int>> vv;
int r, c;

void thinout() {
    for (int i = 0; i < vv.size(); i++) {
        for (int  j = i + 1; j < vv.size(); j++) {
            bool flag = 0;
            for (int k = 0; k < vv[i].size(); k++) {
                if (find(vv[j].begin(), vv[j].end(), vv[i][k]) == vv[j].end()) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {vv.erase(vv.begin() + j); j--;}
        }
    }
}

void check(vector<int> v) {
    unordered_set<string> us;
    for (int i = 0; i < r; i++) {
        string tmp;
        for (int j = 0; j < v.size(); j++) tmp += rel[i][v[j]];
        if (us.find(tmp) != us.end()) return;
        us.insert(tmp);
    }
    vv.push_back(v);
}

void dfs(int col, vector<int> v, int m) {
    if (v.size() == m || col == c) {
        if (v.size() == m) check(v);
        return;
    }
    dfs(col + 1, v, m);
    v.push_back(col);
    dfs(col + 1, v, m);
}

int solution(vector<vector<string>> relation) {
    r = relation.size();
    c = relation[0].size();
    rel = relation;
    vector<int> v;
    for (int i = 1; i <= c; i++) dfs(0, v, i);
    thinout();
    return vv.size();
}