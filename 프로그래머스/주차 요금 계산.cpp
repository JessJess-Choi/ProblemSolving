#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string,int> input;
    map<string,int> m;
    for(string record : records){
        string str = record.substr(0,5);
        string car = record.substr(6,4);
        string info = record.substr(11,record.size() - 11);
        int time = ((str[0]-'0') * 10 + str[1] - '0') * 60 + (str[3]-'0')*10 + str[4]-'0';
        if(info == "IN")
            input[car] = time;
        else{
            m[car] += time - input[car];
            input.erase(input.find(car));
        }
    }
    for(auto a : input)
        m[a.first] += 23 * 60 + 59 - a.second;
    for(auto a : m){
        if(fees[0] >= a.second)answer.push_back(fees[1]);
        else{
            int tmp = a.second - fees[0];
            if(tmp % fees[2])
                answer.push_back(fees[1] + (tmp/fees[2]+1) * fees[3]);
            else
                answer.push_back(fees[1] + tmp/fees[2] * fees[3]);
        }
    }
    return answer;
}
