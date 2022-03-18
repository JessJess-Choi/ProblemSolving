#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<pair<int,int>> v;
    map<int,int> m;
    for(int i=1;i<s.size()-1;i++){
        string str = "";
        while(true){
            if(s[i] != '{' && s[i] != ',')str += s[i];
            i++;
            if(i == s.size() - 1 || s[i] == '}' || s[i] == ',')break;
        }
        if(str != "")
            m[stoi(str)]++;
    }
    for(auto a : m)v.push_back(a);
    sort(v.begin(),v.end(),compare);
    for(auto a : v)answer.push_back(a.first);
    return answer;
}
