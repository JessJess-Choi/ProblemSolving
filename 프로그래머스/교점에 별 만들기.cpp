#include <string>
#include <vector>
#include <algorithm>
#define P pair<int,int>

using namespace std;

P f(vector<int> a, vector<int> b){
    long long A = a[0],B = a[1],C = b[0],D = b[1],E = a[2],F = b[2];
    if(A*D == B*C)return {10000,10000};
    if((B*F - E*D) % (A*D - B*C) == 0 && (E*C - A*F) % (A*D - B*C) == 0)
        return {(B*F - E*D) / (A*D - B*C), (E*C - A*F) / (A*D - B*C)};
    return {10000,10000};
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<P> v;
    for(int i=0;i<line.size();i++)
        for(int j=i+1;j<line.size();j++){
            P tmp =  f(line[i],line[j]);
            if(tmp.first != 10000 && tmp.second != 10000)
                v.push_back(tmp);
        }
    int x1 = v[0].first, x2 = v[0].first, y1 = v[0].second, y2 = v[0].second;
    for(auto a : v){
        x1 = min(x1,a.first);
        x2 = max(x2,a.first);
        y1 = min(y1,a.second);
        y2 = max(y2,a.second);
    }
    string str = "";
    for(int i=0;i<x2-x1+1;i++)str += ".";
    for(int i=0;i<y2-y1+1;i++)
        answer.push_back(str);
    for(auto a : v)
        answer[a.second-y1][a.first-x1] = '*';
    reverse(answer.begin(),answer.end());
    return answer;
}
