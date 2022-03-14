#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int courses : course){
        map<string,int> m;
        for(string order : orders){
            vector<int> v;
            if(order.size() < courses)continue;
            sort(order.begin(),order.end());
            for(int i=0;i<courses;i++)v.push_back(0);
            for(int i=courses;i<order.size();i++)v.push_back(1);
            do{
                string str = "";
                for(int i=0;i<order.size();i++)
                    if(!v[i])
                        str += order[i];
                m[str] += 1;
            }while(next_permutation(v.begin(),v.end()));
        }
        int tmp = 1;
        for(auto a : m)tmp = max(tmp,a.second);
        if(tmp > 1)
            for(auto a : m)
                if(a.second == tmp)
                    answer.push_back(a.first);
    }
    sort(answer.begin(),answer.end());
    return answer;
}
