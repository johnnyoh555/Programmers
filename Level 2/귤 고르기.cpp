// https://school.programmers.co.kr/learn/courses/30/lessons/138476
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> t) {
    int ans = 0;
    map<int, int> m;
    for (int i = 0; i < t.size(); i++) {
        if (m.find(t[i]) == m.end()) m[t[i]] = 1;
        else m[t[i]]++;
    }
    vector<int> v;
    for (auto iter = m.begin(); iter != m.end(); iter++) v.push_back(iter->second);
    sort(v.begin(), v.end(), greater<int>());
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
        ans++;
        if (sum >= k) break;
    }
    return ans;
}