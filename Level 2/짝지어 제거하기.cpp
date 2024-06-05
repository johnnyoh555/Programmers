// https://school.programmers.co.kr/learn/courses/30/lessons/12973
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int ans = 0;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (st.empty() || st.top() != s[i]) st.push(s[i]);
        else st.pop();
    }
    if (st.empty()) ans = 1;
    return ans;
}