#include <algorithm>
using namespace std;
int arr[100001];

int ft(int n) {
    if (arr[n] >= 0) return arr[n];
    return arr[n] = (ft(n - 1) + ft(n - 2)) % 1234567;
}

int solution(int n) {
    fill(arr, arr + 100001, -1);
    arr[0] = 0;
    arr[1] = 1;
    return ft(n);;
}