#include <string>
#include<algorithm>
using namespace std;
int solution(string s) {
    int answer = s.size();
    for(int i=1;i<=s.size()/2;i++){
        string str1 = s.substr(0,i),str2;
        int cnt = 1;
        for(int j=i;j<s.size();j+=i){
            if(str1 == s.substr(j,i))cnt++;
            else{
                if(cnt > 1)str2 += to_string(cnt);
                str2 += str1;
                str1 = s.substr(j,i);
                cnt = 1;
            }
        }
        if(cnt > 1)str2 += to_string(cnt);
        str2 += str1;
        answer = min(answer,(int)str2.size());
    }
    return answer;
}
