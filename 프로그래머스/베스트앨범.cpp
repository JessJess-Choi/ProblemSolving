#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define P pair<int,int>

using namespace std;

bool cmp1(pair<int,vector<P>> a, pair<int,vector<P>> b){
    return a.first > b.first;
}

bool cmp2(P a, P b){
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,pair<int,vector<P>>> m;
    vector<pair<int,vector<P>>> v;
    for(int i=0;i<genres.size();i++){
        m[genres[i]].first += plays[i];
        m[genres[i]].second.push_back({plays[i],i});
    }
    for(auto a : m)
        v.push_back(a.second);
    sort(v.begin(),v.end(),cmp1);
    for(auto &a : v)
        sort(a.second.begin(),a.second.end(),cmp2);
    for(auto a : v){
        for(int i=0;i<2;i++){
            if((int)a.second.size() > i)
                answer.push_back(a.second[i].second);
        }
    }
    return answer;
}
