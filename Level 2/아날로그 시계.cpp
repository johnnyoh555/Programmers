#include <string>
#include <vector>

using namespace std;

struct Degree {
    double dh;
	double dm;
    double ds;
};

Degree getDegree(int h, int m, int s) {
    Degree tmp;
    
    tmp.ds = s * 6.0;
    tmp.dm = m * 6.0 + s * (0.1);
    tmp.dh = (h % 12) * 30.0 + m * (0.5) + s * (1/120.0);
    return tmp;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    Degree after;
    Degree before;
    
	while (h1 != h2 || m1 != m2 || s1 != s2) {
        before = getDegree(h1, m1, s1);
        s1 += 1;
        after = getDegree(h1, m1, s1);
        if (before.ds <= before.dm && after.ds > after.dm) answer++;
        if (before.ds <= before.dh && after.ds > after.dh && before.dh != before.dm) answer++;
        if (s1 == 60) {m1 += 1; s1 = 0;}
        if (m1 == 60) {h1 += 1; m1 = 0;}
    }
    if (after.ds == after.dm) answer++;
    return answer;
}