#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define P pair<string,int>

using namespace std;

bool compare(P a, P b){
    return a.second < b.second;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0, cnt = 0;
    map<string,int> m;
    if(cacheSize == 0)return cities.size() * 5;
    for(auto &a : cities)
        for(auto &b : a)
            if(b >= 'A' && b<= 'Z')
                b += 'a' - 'A';
    for(auto a : cities){
        cnt++;
        if(m.find(a) != m.end())
            answer++;
        else{
            answer += 5;
            if(m.size() >= cacheSize){
                vector<P> v(m.begin(),m.end());
                sort(v.begin(),v.end(),compare);
                string str = v[0].first;
                m[a] = cnt;
                m.erase(str);
            }
        }
        m[a] = cnt;
    }
    return answer;
}
