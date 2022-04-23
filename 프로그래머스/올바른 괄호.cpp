#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    if(s[0] == ')')return false;
    stack<char> st;
    for(char c : s){
        if(c == s[0])st.push(c);
        else{
            if(st.empty())return false;
            else
                st.pop();
        }
    }
    if(!st.empty())return false;
    return true;
}
