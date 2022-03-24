#include <string>
#include <vector>

using namespace std;

void f(string &str){
    while(str.find("#") != string::npos){
        string a = str.substr(0,str.find("#"));
        string b = str.substr(a.size()+1,str.size()-a.size()-1);
        if(a[a.size()-1] == 'A')a[a.size()-1] = 'Z';
        else if(a[a.size()-1] == 'C')a[a.size()-1] = 'Y';
        else if(a[a.size()-1] == 'D')a[a.size()-1] = 'X';
        else if(a[a.size()-1] == 'F')a[a.size()-1] = 'W';
        else if(a[a.size()-1] == 'G')a[a.size()-1] = 'P';
        str = a + b;
    }
}

string solution(string m, vector<string> musicinfos) {
    pair<string,int> answer = {"(None)",0};
    f(m);
    for(auto a : musicinfos){
        string start = a.substr(0,a.find(","));
        a = a.substr(start.size()+1,a.size()-start.size()-1);
        string end = a.substr(0,a.find(","));
        a = a.substr(end.size()+1,a.size()-end.size()-1);
        string name = a.substr(0,a.find(","));
        string music = a.substr(name.size()+1,a.size()-name.size()-1);
        f(music);
        int time1 = ((end[0]-'0') * 10 + (end[1] - '0')) * 60 + (end[3]-'0') * 10 + end[4]-'0';
        int time2 = ((start[0]-'0') * 10 + (start[1] - '0')) * 60 + (start[3]-'0') * 10 + start[4]-'0';
        int n = time1 - time2;
        string full_music = "";
        int len = music.size();
        for(int i=0;i<n/len;i++)full_music += music;
        for(int i=0;i<n%len;i++)full_music += music[i];
        if(full_music.find(m) != string::npos){
            if(answer.first == "(None)"){
                answer.first = name;
                answer.second = n;
            }
            else if(answer.second < n){
                answer.first = name;
                answer.second = n;
            }
        }
    }
    return answer.first;
}
