#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> m;
    for(auto a : participant)m[a] += 1;
    for(auto a : completion)m[a] -= 1;
    for(auto a : participant)
        if(m.find(a) != m.end() && m[a])
            answer = a;
    return answer;
}
