// https://school.programmers.co.kr/learn/courses/30/lessons/176962
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>

using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    priority_queue<tuple<int, int, string>, vector<tuple<int, int, string>>, greater<tuple<int, int, string>> > pq;
    stack<tuple<int, int, string>> left;
    for (int i = 0; i < plans.size(); i++) {
        int a = (plans[i][1][0] - '0') * 600 + (plans[i][1][1] - '0') * 60 + \
            (plans[i][1][3] - '0') * 10 + (plans[i][1][4] - '0');
        int b = 0;
        for (int j = 0; j < plans[i][2].size(); j++) {
            b *= 10;
            b += plans[i][2][j] - '0';
        }
        pq.push({a, b, plans[i][0]});
    }
    int s, t;
    string str;
    tie(s, t, str) = pq.top(); pq.pop();
    while (!pq.empty()) {
        int ns, nt;
        string nstr;
        tie(ns, nt, nstr) = pq.top();
        if (ns > s + t) {
            answer.push_back(str);
            int tmp = ns - (s + t);
            while (tmp && !left.empty()) {
                int xs, xt;
                string xstr;
                tie(xs, xt, xstr) = left.top(); left.pop();
                if (xt <= tmp) {
                    answer.push_back(xstr);
                    tmp -= xt;    
                } else {
                    xt -= tmp;
                    left.push({xs, xt, xstr});
                    break;
                }
            }
        } else if (ns <= s + t) {
            t = (s + t) - ns;
            if (t == 0) answer.push_back(str);
            else left.push({s, t, str});
        }
        tie(s, t, str) = pq.top(); pq.pop();
    }
    answer.push_back(str);
    while (!left.empty()) {
        int c, d;
        string q;
        tie(c, d, q) = left.top(); left.pop();
        answer.push_back(q);
    }
    return answer;
}