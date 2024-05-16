// https://school.programmers.co.kr/learn/courses/30/lessons/42586
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> p, vector<int> s) {
    vector<int> answer;
    vector<int> v;
    for (int i = 0; i < p.size(); i++) {
        int tmp = (100 - p[i] - 1) / s[i] + 1;
        v.push_back(tmp);
    }
    int cnt = 0;
    int mx = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] <= mx) {
            cnt++;
        } else {
            if (cnt) answer.push_back(cnt);
            mx = v[i];
            cnt = 1;
        }
    }
    if (cnt) answer.push_back(cnt);
    return answer;
}