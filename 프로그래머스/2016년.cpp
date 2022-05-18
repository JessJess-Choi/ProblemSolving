#include <string>

using namespace std;

string solution(int a, int b) {
    int arr[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    string str[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    for(int i=1;i<12;i++)arr[i] += arr[i-1];
    return str[(arr[a - 1] + b + 4) % 7];
}
