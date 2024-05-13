// https://school.programmers.co.kr/learn/courses/30/lessons/17683#
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gettime(string time) {
    int sh = (time[0] - '0') * 10 + time[1] - '0';
    int sm = (time[3] - '0') * 10 + time[4] - '0';
    int eh = (time[6] - '0') * 10 + time[7] - '0';
    int em = (time[9] - '0') * 10 + time[10] - '0';
    int ret = (eh * 60 + em) - (sh * 60 + sm);
    return ret;
}

bool checksame(string& tmp, int j, string& m, int idx) {
    if (tmp[j] != m[idx]) return false;
    else {
        bool ts = 0;
        bool ms = 0;
        if (j != tmp.size() - 1 && tmp[j + 1] == '#') ts = 1;
        if (idx != m.size() - 1 && m[idx + 1] == '#') ms = 1;
        if ((ms && ts) || (!ms && !ts)) return true;
        else return false;
    }
}

string solution(string m, vector<string> mi) {
    string answer = "(None)";
    int mx = 0;
    for (int i = 0; i < mi.size(); i++) {
        int time = gettime(mi[i]);
        if (time < mx) continue;
        string tmp = mi[i].substr(12);
        int n = tmp.find(',');
        string name = tmp.substr(0, n);
        tmp = tmp.substr(n + 1);
        int j = 0;
        int idx = 0;
        int t = 0;
        while (t++ < time) {
            if (checksame(tmp, j, m, idx)) {
                idx++;
                if (idx != m.size() && m[idx] == '#') idx++;
            } else {
                idx = 0;
                if (checksame(tmp, j, m, idx)) {
                    idx++;
                    if (idx != m.size() && m[idx] == '#') idx++;
                }
            }
            j++;
            if (j != tmp.size() && tmp[j] == '#') j++;
            if (j == tmp.size()) j = 0;
            if (idx == m.size()) break;
        }
        if (idx == m.size() && mx < time) {answer = name; mx = time;}
    }
    return answer;
}