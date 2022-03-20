#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

struct st{
    string str;
    bool visit, select;
};
set<set<int>> s;
vector<st> v;

bool check(set<int> s1, vector<vector<string>> relation){
    map<string,int> m;
    for(auto a : relation){
        string str = "";
        for(auto it : s1)str = str + a[it] + " ";
        if(!m[str])m[str] = 1;
        else
            return false;
    }
    return true;
}

bool compare(st a, st b){
    if(a.str.size() != b.str.size())return a.str.size() < b.str.size();
    return a.str < b.str;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    for(int size=1;size<=relation[0].size();size++){
        vector<int> v1;
        for(int i=0;i<relation[0].size()-size;i++)v1.push_back(0);
        for(int i=0;i<size;i++)v1.push_back(1);
        do{
            set<int> s1;
            for(int i=0;i<v1.size();i++)
                if(v1[i])s1.insert(i);
            if(check(s1,relation))s.insert(s1);
        }while(next_permutation(v1.begin(),v1.end()));
    }
    for(auto a : s){
        string str = "";
        for(auto b : a)str += to_string(b);
        v.push_back({str,false,false});
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++){
        if(v[i].visit)continue;
        v[i].visit = true;
        for(int j=i+1;j<v.size();j++){
            if(v[j].visit)continue;
            bool tmp = true;
            for(int k=0;k<v[i].str.size();k++){
                string str1 = "";
                str1 += v[i].str[k];
                if(v[j].str.find(str1) == string::npos){
                    tmp = false;
                    break;
                }
            }
            if(tmp){
                v[j].visit = true;
                v[j].select = true;
            }
        }
    }
    for(auto a : v)
        if(!a.select)answer++;
    return answer;
}
