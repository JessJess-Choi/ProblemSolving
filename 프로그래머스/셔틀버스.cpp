#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
int start=540,index,people,ans,hour,minute;
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    sort(timetable.begin(),timetable.end());
    vector<int> time;
    for(auto a : timetable)time.push_back(stoi(a.substr(0,2))*60 + stoi(a.substr(3,2)));
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=index;j<time.size();j++){
            if(time[j] <= start)index++,cnt++;
            if(cnt == m)break;
        }
        if(i+1 == n)
            if(cnt == m)
                ans = time[index-1]-1;
            else
                ans = start;
        start += t;
        if(start >= 1440)break;
    }
    hour = ans / 60;
    minute = ans % 60;
    if(hour < 10)answer += "0" + to_string(hour);
    else
        answer += to_string(hour);
    answer += ":";
    if(minute < 10)answer += "0" + to_string(minute);
    else
        answer += to_string(minute);
    return answer;
}
