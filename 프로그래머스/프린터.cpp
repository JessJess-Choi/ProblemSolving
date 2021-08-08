#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<pair<int,int>> v;
    pair<int,int> tmp;
    for(int i=0;i<priorities.size();i++)
        v.push_back(make_pair(priorities[i],i));
    tmp = v[location];
    while(true){
        bool check = false;
        int maxN = -1;
        for(auto a : v)maxN = max(a.first,maxN);
        if(maxN == v[0].first){
            if(tmp == v[0]){
                check = true;
                break;
            }
            else{
                answer++;
                v.erase(v.begin());
            }
        }
        else{
            v.push_back(v[0]);
            v.erase(v.begin());
        }
        if(check)break;
    }
    return ++answer;
}
