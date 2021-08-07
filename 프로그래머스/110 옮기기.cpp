#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for(auto str : s){
        int cnt = 0,index = -1;
        string tmp = "";
        for(auto a : str){
            tmp += a;
            if(tmp.size() >= 3 && tmp.substr(tmp.size()-3,3) == "110"){
                cnt++;
                tmp.erase(tmp.size()-3,3);
            }
        }
        for(int i=tmp.size()-1;i>=0;i--)
            if(tmp[i] == '0'){
                index = i;
                break;
            }
        string ans = "";
        if(index == -1){
            while(cnt--)ans += "110";
            ans += tmp;
        }
        else{
            for(int i=0;i<tmp.size();i++)
                if(i == index){
                    ans += tmp[i];
                    while(cnt--)ans += "110";
                }
                else
                    ans += tmp[i];
        }
        answer.push_back(ans);
    }
    return answer;
}
