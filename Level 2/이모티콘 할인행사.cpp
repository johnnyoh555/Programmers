#include <string>
#include <vector>

using namespace std;
pair<int, int> arr[7];
vector<int> e;
vector<vector<int>> u;
vector<int> answer(2, 0);

void    check() {
    int cnt = 0, sum = 0;
    for (int i = 0; i < u.size(); i++) {
        int tmp = 0;
        for (int j = 0; j < e.size(); j++)
            if (arr[j].first >= u[i][0]) tmp += arr[j].second;
        if (tmp >= u[i][1]) cnt++;
        else sum += tmp;
    }
    if (cnt > answer[0]) {answer[0] = cnt; answer[1] = sum;}
    else if (cnt == answer[0] && sum > answer[1]) answer[1] = sum;
}

void    ft(int dep) {
    if (dep == e.size()) {
        check();
        return;
    }
    for (int i = 40; i > 0; i -= 10) {
        arr[dep] = {i, e[dep] * (100 - i) / 100};
        ft(dep + 1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    u = users;
    e = emoticons;
    ft(0);
    return answer;
}