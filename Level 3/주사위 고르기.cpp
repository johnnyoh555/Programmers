#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> d;
vector<int> answer;
int n, cnt, mx;

void ft_1(int sum, int dep, vector<int>& v, vector<int>& r) {
    if (dep == v.size()) {r.push_back(sum); return;}
    for (int i = 0; i < 6; i++) {
        ft_1(sum + d[v[dep]][i], dep + 1, v, r);
    }    
}

void count(vector<int>& a, vector<int>& b) {
    vector<int> f;
    vector<int> s;
    ft_1(0, 0, a, f);
    ft_1(0, 0, b, s);
    sort(f.begin(), f.end());
    sort(s.begin(), s.end());
    int i = 0;
    int j = 0;
    int cnt = 0;
    while (i < f.size() && j < s.size()) {
        if (f[i] > s[j]) j++;
        else {cnt += j; i++;}
    }
    if (j == s.size()) {
        cnt += s.size() * (f.size() - i);
    }
    if (cnt > mx) {mx = cnt; answer = a;}
}

void    dfs(int dep, vector<int>& a, vector<int>& b) {
    if (dep == n) {count(a, b); return;}
    if (a.size() < n / 2) {
        a.push_back(dep);
        dfs(dep + 1, a, b);
        a.pop_back();
    }
    if (b.size() == n / 2) return;
    b.push_back(dep);
    dfs(dep + 1, a, b);
    b.pop_back();
}

vector<int> solution(vector<vector<int>> dice) {
    d = dice;
    n = dice.size();
    vector<int> a;
    vector<int> b;
    dfs(0, a, b);
    for (int i = 0; i < answer.size(); i++) answer[i]++;
    return answer;
}