#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    string str[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    string tmp = "";
    for(auto a : s){
        if(a >='0' && a<='9'){
            answer*=10;
            answer+=a-'0';
        }
        else{
            tmp += a;
            if(find(str,str+10,tmp) != str+10){
                answer *= 10;
                answer += find(str,str+10,tmp) -str;
                tmp = "";
            }
        }
        cout<<answer<<'\n';
    }
    return answer;
}
