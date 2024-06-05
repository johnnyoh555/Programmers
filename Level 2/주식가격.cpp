// https://school.programmers.co.kr/learn/courses/30/lessons/42584
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> p) {
    stack<pair<int, int>> s;
    vector<int> ans(p.size());
    for (int i = 0; i < p.size(); i++) {
        while (!s.empty() && s.top().first > p[i]) {
            ans[s.top().second] = i - s.top().second;
            s.pop();
        }
        s.push({p[i], i});
    }
    while (!s.empty()) {
        ans[s.top().second] = p.size() - 1 - s.top().second;
        s.pop();
    }
    return ans;
}