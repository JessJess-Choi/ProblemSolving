#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string arr = "0123456789ABCDEF";

string f(int a,int b){
    string ret = "";
    if(a == 0)return "0";
    while(a){
        ret += arr[a%b];
        a /= b;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
    
string solution(int n, int t, int m, int p) {
    string answer = "", tmp = "";
    for(int i=0;i<m*t;i++)tmp += f(i,n);
    while(answer.size() < t){
        answer += tmp[p-1];
        p += m;
    }
    return answer;
}
