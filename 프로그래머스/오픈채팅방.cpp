#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer, tmp;
    map<string,string> m;
    for(auto a : record){
        string str,id,name;
        int index1 = a.find(' '), index2;
        str = a.substr(0,index1);
        index2 = a.substr(index1 + 1,a.size() - index1 - 1).find(' ');
        id = a.substr(index1 + 1,index2);
        name = a.substr(index1 + index2 + 2,a.size() - index1 - index2 - 2);
        if(str[0] == 'E' || str[0] == 'C')m[id] = name;
        if(str[0] == 'E')tmp.push_back(id + "님이 들어왔습니다.");
        else if(str[0] == 'L')tmp.push_back(id + "님이 나갔습니다.");
    }
    for(auto a : tmp){
        int index = a.find("님");
        answer.push_back(m[a.substr(0,index)] + a.substr(index,a.size() - index));
    }
    return answer;
}
