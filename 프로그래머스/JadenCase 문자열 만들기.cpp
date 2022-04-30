#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    while(s.find(" ") != string::npos){
        string str = s.substr(0,s.find(" "));
        if(str[0] >= 'a' && str[0] <= 'z')str[0] += 'A' - 'a';
        for(int i=1;i<str.size();i++)
            if(str[i] >= 'A' && str[i] <= 'Z')str[i] += 'a' - 'A';
        answer += str + " ";
        s = s.substr(str.size()+1,s.size()-str.size()-1);
    }
    if(s[0] >= 'a' && s[0] <= 'z')s[0] += 'A' - 'a';
    for(int i=1;i<s.size();i++)
        if(s[i] >= 'A' && s[i] <= 'Z')s[i] += 'a' - 'A';
    return answer + s;
}
