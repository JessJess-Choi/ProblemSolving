#include <vector>
#include<set>

using namespace std;

bool f(set<vector<int>>& s){
    for(auto a : s){
        int x = a[0],y = a[1],z = a[2];
        if(z == 0){
            vector<int> tmp[3]={{x,y-1,0},{x,y,1},{x-1,y,1}};
            if(y==0 || s.find(tmp[0])!=s.end() || s.find(tmp[1])!=s.end() || s.find(tmp[2])!=s.end())continue;
            return false;
        }
        else{
            vector<int> tmp[4]={{x,y-1,0},{x+1,y-1,0},{x+1,y,1},{x-1,y,1}};
            if(s.find(tmp[0])!=s.end() || s.find(tmp[1])!=s.end() || (s.find(tmp[2])!=s.end() && s.find(tmp[3])!=s.end()))continue;
            return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    set<vector<int>> s;
    for(auto a : build_frame){
        vector<int> v = {a[0],a[1],a[2]};
        if(a[3] == 0){
            s.erase(v);
            if(!f(s))s.insert(v);
        }
        else{
            s.insert(v);
            if(!f(s))s.erase(v);
        }
    }
    for(auto a : s)answer.push_back(a);
    return answer;
}
