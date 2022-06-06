#include <string>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(char ch : s){
        if(ch >= 'a' && ch <= 'z'){
            if(ch + n > 'z')answer += ch + n - 'z' + 'a' - 1;
            else answer += ch + n;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            if(ch + n > 'Z')answer += ch + n - 'Z' + 'A' - 1;
            else answer += ch + n;
        }
        else
            answer += ch;
    }
    return answer;
}
