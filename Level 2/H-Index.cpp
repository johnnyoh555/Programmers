// https://school.programmers.co.kr/learn/courses/30/lessons/42747
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> c) {
    int ans = 0;
    sort(c.begin(), c.end(), greater<int>());
    for (int i = 0; i < c.size(); i++)
        if (i + 1 <= c[i] && i + 1 > ans) ans = i + 1;
    return ans;
}