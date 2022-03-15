#include <string>
#include <stack>

using namespace std;

bool check(string p){
    stack<char> s;
    if(p[0] == ')')return false;
    for(auto a : p){
        if(a == p[0])s.push(a);
        else{
            if(s.empty())return false;
            else s.pop();
        }
    }
    if(!s.empty())return false;
    return true;
}

string solution(string p){
    string u = "", v = "";
    if(p == "")return p;
    int cnt1 = 0, cnt2 = 0;
    for(auto a : p){
        if(a == p[0])cnt1++;
        else cnt2++;
        u += a;
        if(cnt1 == cnt2)break;
    }
    v = p.substr(u.size(), p.size() - u.size());
    if(check(u))
        return u + solution(v);
    else{
        string str = "(" + solution(v) + ")";
        for(int i=1;i<u.size()-1;i++)
            if(u[i] == '(')
                str += ')';
            else
                str += '(';
        return str;
    }
}
