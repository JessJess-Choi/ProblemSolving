#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string,int> dic;
    int number = 1, indx;
    for(char ch='A';ch<='Z';ch++){
        string str = "";
        str += ch;
        dic[str] = number++;
    }
    for(int i=0;i<msg.size();i++){
        indx = i;
        string now = "";
        while(true){
            now += msg[indx];
            if(!dic[now])
                break;
            string tmp = now + msg[indx+1];
            if(!dic[tmp])
                answer.push_back(dic[now]);
            indx++;
            if(indx == msg.size())break;
        }
        if(indx != msg.size())dic[now] = number++;
        i = indx - 1;
    }
    return answer;
}
