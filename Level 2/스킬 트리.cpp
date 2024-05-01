// https://school.programmers.co.kr/learn/courses/30/lessons/49993
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<int> v(26, -1);
    vector<int> d(26, 0);
    char c;
    for (int i = 0; i < skill.size(); i++) {
        if (i) {v[c - 'A'] = skill[i] - 'A'; d[skill[i] - 'A']++;}
        c = skill[i];
    }
    for (int i = 0; i < skill_trees.size(); i++) {
        vector<int> tmp = d;
        bool flag = 0;
        for (int j = 0; j < skill_trees[i].size(); j++) {
            if (tmp[skill_trees[i][j] - 'A']) {flag = 1; break;}
            if (v[skill_trees[i][j] - 'A'] != -1) tmp[v[skill_trees[i][j] - 'A']]--;
        }
        if (!flag) answer++;
    }
    return answer;
}