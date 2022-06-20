#include <string>
#include <vector>
#include <algorithm>
#define P pair<int,int>

using namespace std;

bool compare(P a, P b){
    return a.second < b.second;
}

int solution(vector<string> lines) {
    int answer = 1;
    vector<P> v;
    for(string line : lines){
        line = line.substr(line.find(" ") + 1, line.size() - line.find(" ") - 1);
        string time = line.substr(0,line.find(" "));
        string second = line.substr(time.size() + 1, line.size() - time.size() - 1);
        int start = 0, end = 0, milisecond = 0;
        end = ((time[0]-'0')*10+time[1]-'0')*60*60*1000 + ((time[3]-'0')*10+time[4]-'0')*60*1000 + (time[6]-'0')*10000 + (time[7]-'0')*1000 + (time[9]-'0')*100 + (time[10]-'0')*10 + time[11]-'0';
        if(second.find(".") == string::npos){
            for(char ch : second)
                if(ch != 's')
                    milisecond = milisecond * 10 + ch - '0';
            milisecond *= 1000;
        }
        else{
            for(char ch : second)
                if(ch != 's' && ch != '.')
                    milisecond = milisecond * 10 + ch - '0';
            for(int i=0;i<6-second.size();i++)milisecond *= 10;
        }
        start = end - milisecond + 1;
        v.push_back({start,end});
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size()-1;i++){
        int cnt = 1;
        for(int j=i+1;j<v.size();j++){
            if(v[j].first - v[i].second < 1000)cnt++;
        }
        answer = max(answer,cnt);
    }
    return answer;
}
