#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    map<string, set<string>> m;
    map<string,int> id_index;
    for(int i=0;i<id_list.size();i++)id_index[id_list[i]] = i;
    for(auto a : report){
        int index = a.find(" ");
        string str1 = a.substr(0,index);
        string str2 = a.substr(index + 1, a.size() - index - 1);
        m[str2].insert(str1);
    }
    for(auto a : m)
        if(a.second.size() >= k)
            for(auto b : a.second)
                answer[id_index[b]]++;
    return answer;
}

/*      시간초과
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    map<pair<string,string>, int> m;
    map<string,int> cnt;
    map<string,int> id_index;
    for(int i=0;i<id_list.size();i++)id_index[id_list[i]] = i;
    for(auto a : report){
        int index = a.find(" ");
        string str1 = a.substr(0,index);
        string str2 = a.substr(index + 1, a.size() - index - 1);
        m[{str1,str2}] = 1;
    }
    for(auto a : m)cnt[a.first.second]++;
    for(auto a : cnt)
        if(a.second >= k)
            for(auto b : m)
                if(b.first.second == a.first)
                    answer[id_index[b.first.first]]++;
    return answer;
}
*/
