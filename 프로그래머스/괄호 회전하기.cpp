#include <string>
#include<stack>
using namespace std;
int f(string str){
    stack<char> st;
    for(auto a : str){
        if(a=='(' || a=='{' || a=='[')st.push(a);
        else
            if(st.empty())return 0;
            else if(a==')'){
                if(st.top() == '(')st.pop();
                else
                    return 0;
            }
            else if(a==']'){
                if(st.top() == '[')st.pop();
                else
                    return 0;
            }
            else if(a=='}'){
                if(st.top() == '{')st.pop();
                else
                    return 0;
            }
    }
    return st.empty()?1:0;
}
int solution(string s) {
    int answer = 0;
    answer += f(s);
    for(int i=1;i<s.size();i++)
        answer += f(s.substr(i,s.size()) + s.substr(0,i));
    return answer;
}
