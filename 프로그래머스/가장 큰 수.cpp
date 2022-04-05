#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool compare(string a,string b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(int i : numbers){
        v.push_back(to_string(i));
    }
    sort(v.begin(),v.end(),compare);
    for(string s : v)
        answer += s;
    if(answer[0] == '0')return "0";
    return answer;
}
