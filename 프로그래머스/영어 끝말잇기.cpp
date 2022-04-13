#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string,int> m;
    string before = words[0];
    m[before] = 1;
    for(int i=1;i<words.size();i++){
        if(before[before.size()-1] == words[i][0] && !m[words[i]]){
            m[words[i]] = 1;
            before = words[i];
        }
        else{
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }
    }
    if(!answer.size()){
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
