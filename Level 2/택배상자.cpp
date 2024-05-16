// https://school.programmers.co.kr/learn/courses/30/lessons/131704
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    stack<int> t;
    for (int i = order.size(); i > 0; i--) s.push(i);
    int i = 0;
    while (i < order.size()) {
        if (!s.empty() && s.top() == order[i]) {
            s.pop();
            answer++;
            i++;
        } else if (!t.empty() && t.top() == order[i]) {
            t.pop();
            answer++;
            i++;
        } else if (!s.empty()) {
            t.push(s.top());
            s.pop();
        } else {
            break;
        }
    }
    return answer;
}