#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    while(true){
        string str = s.substr(0,s.find(" "));
        v.push_back(stoi(str));
        s = s.substr(str.size()+1,s.size()-str.size()-1);
        if(s.find(" ") == string::npos){
            v.push_back(stoi(s));
            break;
        }
    }
    sort(v.begin(),v.end());
    return to_string(v[0]) + " " + to_string(v[v.size()-1]);
}
