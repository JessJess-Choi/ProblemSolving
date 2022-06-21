#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool f(vector<string> v, vector<string> ban){
    for(int i=0;i<v.size();i++){
        if(ban[i].size() != v[i].size())return false;
        for(int j=0;j<v[i].size();j++){
            if(ban[i][j] != '*' && ban[i][j] != v[i][j])return false;
        }
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<vector<string>> ans;
    sort(user_id.begin(),user_id.end());
    do{
        vector<string> v;
        for(int i=0;i<banned_id.size();i++)
            v.push_back(user_id[i]);
        if(f(v,banned_id))ans.push_back(v);
    }while(next_permutation(user_id.begin(),user_id.end()));
    for(auto &a : ans)
        sort(a.begin(),a.end());
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    return (int)ans.size();
}
