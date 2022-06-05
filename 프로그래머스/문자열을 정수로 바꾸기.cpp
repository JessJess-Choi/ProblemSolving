#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    if(s[0] != '+' && s[0] != '-')answer = s[0] - '0';
    for(int i=1;i<s.size();i++)
        answer = answer * 10 + s[i] - '0';
    if(s[0] == '-')answer = -answer;
    return answer;
}
